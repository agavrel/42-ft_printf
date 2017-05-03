/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 19:16:05 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/03 06:36:19 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_printf.h"

/*
** 						~ FLAGS ~
**
** flags interract between them, if there is a minus then it
** cancels the zero flag. if there is a + it cancels the sp flag.
** sharp is to add the prefix 0x for hexa for example
*/

static void	parse_flags(t_printf *p)
{
	int		tmp;
	short	n;

	while ((n = ft_strchr_index("#0+- *", *p->format)) > -1 && ++p->format)
		p->f |= (1 << n);
	if (p->f & F_MINUS)
		p->f &= ~F_ZERO;
	if (p->f & F_PLUS)
		p->f &= ~F_SPACE;
	if (p->f & F_WILDCARD)
	{
		tmp = (int)va_arg(p->ap, int);
		p->f &= ~F_WILDCARD;
		p->f = (tmp < 0) ? p->f | F_MINUS : p->f & ~F_MINUS;
		tmp = ABS(tmp);
		if (!(p->f & F_APP_PRECI))
			p->min_length = tmp;
		else
		{
			p->precision = (!(p->f & F_MINUS)) ? tmp : 0;
			p->f = (!tmp) ? p->f | F_APP_PRECI : p->f & ~F_APP_PRECI;
		}
	}
}

/*
** 						~ FIELD WIDTH ~
** if (48 < *p->format && *p->format < 58)
** An optional decimal digit string (with nonzero first digit) specifying a
** minimum field width. If the converted value has fewer characters than the
** field width, it will be padded with spaces on the left (or right, if the
** left-adjustment flag has been given). Instead of a decimal digit string
** one may write "*" or "*m$" (for some decimal integer m) to specify that
** the field width is given in the next argument, or in the m-th argument,
** respectively, which must be of type int. A negative field width is taken
** as a '-' flag followed by a positive field width. In no case does a
** nonexistent or small field width cause truncation of a field; if the result
** of a conversion is wider than the field width, the field is expanded to
** contain the conversion result.
**
** 2nd if : if there is a conv. specifier after the field width for a base it
** will reset the min_length to 0 EXCEPT if it was a padding with 0s ...
**
** 49 is ASCII for 1 and 57 for 9
*/

/*
** 						~ PRECISION ~
** if (*p->format == '.')
** An optional precision, in the form of a period ('.') followed by an optional
** decimal digit string. Instead of a decimal digit string one may write "*" or
** "*m$" (for some decimal integer m) to specify that the precision is given in
** the next argument, or in the m-th argument, respectively, which must be of
** type int. If the precision is given as just '.', or the precision is
** negative, the precision is taken to be zero. This gives the minimum number
** of digits to appear for d, i, o, u, x, and X conversions, the number of
** digits to appear after the radix character for a, A, e, E, f, and F
** conversions, the maximum number of significant digits for g and G
** conversions, or the maximum number of characters to be printed from a
** string for s and S conversions.
*/

/*
** 						~ LENGTH MODIFIER ~
** while (ft_strchr("hljzL", *p->format))
** converts into short, shortshort, long, long long, int_max, size_t depending
** on the input, respectively : h, hh, l, ll, j, z
*/

static void	field_width_precision(t_printf *p)
{
	if (48 < *p->format && *p->format < 58)
	{
		p->min_length = MAX(1, ft_atoi(p->format));
		while (47 < *p->format && *p->format < 58)
			++p->format;
	}
	if (*p->format == '.' && ++p->format)
	{
		p->precision = MAX(ft_atoi(p->format), 0);
		while (47 < *p->format && *p->format < 58)
			++p->format;
		p->f |= F_APP_PRECI;
	}
}

/*
** returns position of a character in a string
*/

static int	ft_strchr_index_2(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c || s[i] == c + 32)
			return (i);
		++i;
	}
	return (-1);
}

/*
** 						~ CONVERSION SPECIFIER ~
**
** A character that specifies the type of conversion to be applied
** if the character following % is a % then is it acts as an ESC char
** The conversion specifiers and their meanings are:
** 1) d, i, D : signed int
** 2) o, u, x, X : unsigned octal, uns. decimal, uns. hexa lower and uppercase
** 3) b, B for unsigned binary
** 3) c, C : char and large char
** 4) s : pointer to a string
** 5) n : the number of characters written so far is stored into the integer
** indicated by the int * pointer argument. No argument is converted.
** 6) m : Print output of strerror(errno). no arg. required
** 7) {} : adds color
** if the character is uppercase then p->cs.uppercase will be set to 1.
*/

static void	conversion_specifier(t_printf *p)
{
	p->printed = 0;
	if (ft_strchr("oOuUbBxX", *p->format))
		pf_putnb_base(ft_strchr_index_2(".b..ou..x", *p->format) << 1, p);
	else if (ft_strchr("dDi", *p->format))
		pf_putnb(p);
	else if (*p->format == 'c' || *p->format == 'C')
		pf_character(p);
	else if (*p->format == 's')
		(p->f & LM_LONG || p->f & LM_LONG2) ? pf_wide_string(p) : pf_string(p);
	else if (*p->format == 'S')
		pf_wide_string(p);
	else if (*p->format == 'p')
		print_pointer_address(p);
	else if (*p->format == 'n')
		*va_arg(p->ap, int *) = p->len;
	else if (*p->format == 'm')
		ft_printf_putstr(strerror(errno), p);
	else if (*p->format == 'f' || *p->format == 'F')
		(p->f & F_APP_PRECI && !p->precision) ? pf_putnb(p) : pf_putdouble(p);
	else if (*p->format == '{')
		color(p);
	else
		cs_not_found(p);
}

/*
** 						~ PARSING OPTONAL INPUTS ~
**
** here we parse the % to check for optional inputs :
** 1) flags, 2) field width, 3) precision and 4) length modifiers.
** Please refer to the man for a more accurate and full description.
** 5) the call to wildcard_length_modifier is a bonus where the '*' given
** the field_width or precision in the va_list ap.
** 6) the second call to parse_flags is to handle undefined behaviors.
*/

void		parse_optionals(t_printf *p)
{
	p->f = 0;
	p->min_length = 0;
	p->precision = 1;
	parse_flags(p);
	field_width_precision(p);
	while (ft_strchr("hljzL", *p->format))
	{
		if (*p->format == 'h')
			p->f |= (*(p->format + 1) == 'h' && ++p->format) ?
				LM_SHORT2 : LM_SHORT;
		else if (*p->format == 'l')
			p->f |= (*(p->format + 1) == 'l' && ++p->format) ?
				LM_LONG2 : LM_LONG;
		else if (*p->format == 'j')
			p->f |= LM_INTMAX;
		else if (*p->format == 'z')
			p->f |= LM_SIZE_T;
		++p->format;
	}
	parse_flags(p);
	if (ft_strchr("CDSUOBX", *p->format))
		p->f |= LM_LONG;
	conversion_specifier(p);
}
