/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angavrel <angavrel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:29:58 by angavrel          #+#    #+#             */
/*   Updated: 2017/05/06 01:28:26 by angavrel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define LBITS 0x101010101010101L
# define HBITS 0x8080808080808080L
# include <unistd.h>
# include <string.h>
# include <stdlib.h>

size_t				ft_strlen(const char *str);
int					ft_strchr_index(char *s, int c);
int					ft_atoi_incr(char *s);
void				ft_bzero(void *s, size_t n);
void				*ft_memchr(const void *mem, const unsigned char c,
										size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
double				ft_pow(double n, int pow);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
size_t				ft_wcharlen(unsigned c);
size_t				ft_wstrlen(unsigned *s);

#endif
