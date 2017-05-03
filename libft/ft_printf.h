/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:37:46 by angavrel          #+#    #+#             */
/*   Updated: 2017/02/17 11:17:45 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MAX(a, b)			b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b)			a & ((a - b) >> 31) | b & (~(a - b) >> 31)
# define ABS(a)				(a < 0) ? -a : a
# define COLOR(s,n)			ft_putstr(s), (format += n)
# define PF_RED				"\033[31m"
# define PF_GREEN			"\033[32m"
# define PF_YELLOW			"\033[33m"
# define PF_BLUE			"\033[34m"
# define PF_PURPLE			"\033[35m"
# define PF_CYAN			"\033[36m"
# define PF_EOC				"\033[36m"

# include "../libft/libft.h"
# include <stdarg.h>
# include <errno.h>

/*
** refer to parsing.c for description of variables in below structures
*/

typedef struct	s_flags
{
	int sharp;
	int zero;
	int min;
	int plus;
	int sp;
}				t_flags;

typedef	struct	s_length_modifier
{
	int sshort;
	int llong;
	int intmax;
	int sizet;
}				t_length_modifier;

typedef struct	s_conversion_specifier
{
	int upcase;
}				t_conversion_specifier;

typedef struct	s_printf
{
	int						len;
	t_flags					flags;
	int						min_length;
	int						precision;
	int						apply_precision;
	t_length_modifier		lm;
	t_conversion_specifier	cs;
	int						printed;
}				t_printf;

/*
** main program
*/

int				ft_printf(char *format, ...);
int				ft_printf_putchar(char c);

/*
** parsing optional parameters
*/

char			*parse_optionals(char *format, va_list ap, t_printf *p);
char			*parse_flags(char *format, t_flags *flags);
char			*field_width(char *format, t_printf *p);
char			*precision(char *format, t_printf *p);
char			*length_modifier(char *format, t_length_modifier *lm);

/*
** parsing conversion specifier
*/

int				percent_char(t_printf *p);
char			*conversion_specifier(char *format, va_list ap, t_printf *p);
void			cs_not_found(char *format, t_printf *p);
void			ft_putnchar(int len, char c);

/*
** number related functions
*/

void			pf_putnb(va_list ap, t_printf *p);
void			pf_putnb_base(int base, va_list ap, t_printf *p);
char			*itoa_printf(intmax_t d, t_printf *p);
char			*itoa_base_printf(uintmax_t d, int b, t_printf *p);
void			itoa_base_fill(uintmax_t tmp, int base, char *str, t_printf *p);

/*
** strings and characters related functions
*/

int				pf_string(va_list ap, t_printf *p);
int				pf_wide_string(va_list ap, t_printf *p);
void			pf_character(va_list ap, t_printf *p);
void			pf_putchar(char c, t_printf *p);
int				ft_printf_putstr(char *s, t_printf *p);
int				ft_printf_putwstr(wchar_t *s);

/*
** bonus
*/

int				print_pointer_address(va_list ap, t_printf *p);
void			wildcard_length_modifier(va_list ap, t_printf *p);
char			*color(char *format, t_printf *p);
void			pf_putdouble(va_list ap, t_printf *p);
char			*pf_ldtoa(double n, t_printf *p);
void			ldtoa_fill(double n, char *s, t_printf *p);

#endif
