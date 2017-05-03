/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:37:46 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/03 10:09:07 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MAX(a, b)			b & ((a - b) >> 31) | a & (~(a - b) >> 31)
# define MIN(a, b)			a & ((a - b) >> 31) | b & (~(a - b) >> 31)
# define ABS(a)				(a < 0) ? -a : a
# define COLOR(s,n)			ft_putstr(s), (p->format += n)
# define PF_RED				"\033[31m"
# define PF_GREEN			"\033[32m"
# define PF_YELLOW			"\033[33m"
# define PF_BLUE			"\033[34m"
# define PF_PURPLE			"\033[35m"
# define PF_CYAN			"\033[36m"
# define PF_EOC				"\033[36m"

# include "libft.h"
# include <stdarg.h>
# include <errno.h>

/*
** refer to parsing.c for description of variables in below structures
*/

# define F_SHARP			(1 << 0)
# define F_SPACE			(1 << 1)
# define F_PLUS				(1 << 2)
# define F_MINUS			(1 << 3)
# define F_ZERO				(1 << 4)
# define LM_LONG			(1 << 5)
# define LM_LONG2			(1 << 6)
# define LM_SHORT			(1 << 7)
# define LM_SHORT2			(1 << 8)
# define LM_INTMAX			(1 << 9)
# define LM_SIZE_T			(1 << 10)
# define F_MIN_LEN			(1 << 11)
# define F_APP_PRECI		(1 << 12)
# define F_WILDCARD			(1 << 13)
# define PF_BUF_SIZE		64

/*
** f stands for flag, listed above
*/

typedef struct	s_printf
{
	int			len;
	short		f;
	int			min_length;
	int			precision;
	int			padding;
	int			printed;
	int			fd;
	int			buffer_index;
	char		buff[PF_BUF_SIZE];
	va_list		ap;
	char		*format;
	unsigned	c;
}				t_printf;

/*
** main program
*/

int				ft_printf(const char *format, ...);

/*
** parsing optional parameters
*/

void			parse_optionals(t_printf *p);

/*
** parsing conversion specifier
*/

void			cs_not_found(t_printf *p);

/*
** number related functions
*/

void			pf_putnb(t_printf *p);
void			pf_putnb_base(int base, t_printf *p);
void			itoa_printf(intmax_t d, t_printf *p);
void			itoa_base_printf(uintmax_t d, int b, t_printf *p);
void			itoa_base_fill(uintmax_t tmp, int base, char *str, t_printf *p);

/*
** strings and characters related functions
*/

void			pf_string(t_printf *p);
void			pf_wide_string(t_printf *p);
void			pf_character(t_printf *p, unsigned c);
void			ft_printf_putstr(char *s, t_printf *p);
void			ft_printf_putwstr(wchar_t *s, t_printf *p);
void			pf_putwchar(t_printf *p, unsigned int wc, int wlen, int n);

/*
** bonus
*/

void			print_pointer_address(t_printf *p);
void			color(t_printf *p);
void			pf_putdouble(t_printf *p);

/*
** misc
*/

int				ft_strchr_index(char *s, int c);
void			buffer(t_printf *p, void *new, size_t size);
void			padding(t_printf *p, int n);

#endif
