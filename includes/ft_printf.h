/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 18:37:46 by angavrel          #+#    #+#             */
/*   Updated: 2017/10/14 16:35:08 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** --------------------------- Librairies --------------------------------------
*/

# include "libft.h"
# include <stdarg.h>
# include <errno.h>
# include <stdint.h>
# define PF_BUF_SIZE	64
# define MAX(a, b)		((b & ((a - b) >> 31)) | (a & (~(a - b) >> 31)))
# define MIN(a, b)		((a & ((a - b) >> 31)) | (b & (~(a - b) >> 31)))

/*
** --------------------------- Masks Definition --------------------------------
*/
/*
typedef struct	s_flag
{
	short		sharp : 1;
	short		space : 1;
	short		plus : 1;
	short		minus : 1;
	short		zero : 1;
	short		wildcard : 1;
	short		upcase : 1;
	short		short1 : 1;
	short		short2 : 1;
	short		long1 : 1;
	short		long2 : 1;
	short		intmax : 1;
	short		sizet : 1;
	short		min_len : 1;
	short		app_preci : 1;
	short		pointer : 1;
}				t_flag;
*/
# define F_SHARP		(1 << 0)
# define F_SPACE		(1 << 1)
# define F_PLUS 		(1 << 2)
# define F_MINUS    	(1 << 3)
# define F_ZERO			(1 << 4)
# define F_WILDCARD		(1 << 5)
# define F_UPCASE		(1 << 6)
# define F_SHORT		(1 << 7)
# define F_SHORT2		(1 << 8)
# define F_LONG			(1 << 9)
# define F_LONG2		(1 << 10)
# define F_INTMAX		(1 << 11)
# define F_SIZE_T		(1 << 12)
# define F_MIN_LEN		(1 << 13)
# define F_APP_PRECI	(1 << 14)
# define F_POINTER		(1 << 15)

/*
** --------------------------- ft_printf variables -----------------------------
** A) Printf writes the output and then returns the len (int)
** B) f stands for flag, defined above and extensively described in parsing.c
** C) min_length (digit after %) and precision (. after %) ~ parsing.c
** D) padding is the resulting from C and the output length.
** E) printed is the temporary len of chars to be send to the buffer
** F) fd is the file descriptor. 1 for ft_printf and can be any with ft_dprintf
** G) buffer_index and buff are related to the buffer function ~ buffer.c
** H) the variadic list (va_list ap) and the format are stored in the structure
** I) c is a temp char (as unsigned int) in order to have a single declaration
*/

typedef struct	s_printf
{
	int			len;
//	t_flag		flag;
	uint8_t		base;
	short		f;
	int			min_length;
	int			preci;
	int			padding;
	int			printed;
	int			fd;
	size_t		buffer_index;
	char		buff[PF_BUF_SIZE];
	va_list		ap;
	char		*format;
	unsigned	c;
	int			i;
	int			n;
}				t_printf;

/*
** function pointer to redirect to the correct function according to the
** corresponding conversion specifier
*/

typedef void (*funPointerArray)(t_printf*);

/*
** --------------------------- ft_printf main functions ------------------------
*/

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);
char			*ft_sprintf(const char *format, ...);
void			parse_optionals(t_printf *p);
void			cs_not_found(t_printf *p);

/*
** --------------------------- number related functions ------------------------
** %d %D %i %f %F %b %B %o %O %u %U %h %H %a %A
*/

void			pf_putnb(t_printf *p);
void			pf_putnb_base(t_printf *p);
void			itoa_printf(__intmax_t d, t_printf *p, int len);
void			itoa_base_printf(__uintmax_t d, int b, t_printf *p);
void			pf_putdouble(t_printf *p);

/*
** --------------------------- number related functions ------------------------
**  %s %S %c %C
*/

void			pf_putstr(t_printf *p);
void			pf_putwstr(t_printf *p);
void			pf_character(t_printf *p);
void			pf_puterror(t_printf *p);

/*
** --------------------------- miscellaneous functions -------------------------
*/

void			buffer(t_printf *p, void *new, size_t size);
void			padding(t_printf *p, int n);
void			print_pointer_address(t_printf *p);

/*
** --------------------------- colors related defines --------------------------
*/

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_PURPLE		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_EOC			"\033[36m"

#endif
