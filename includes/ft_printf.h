/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:07:50 by conoel            #+#    #+#             */
/*   Updated: 2018/12/17 18:33:29 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# define BUFF 2048
# define I all->str_index

/*
**	Concernant le "intflags"
**	0 = nothing
**	1 = l
**	2 = ll
**	3 = h
**	4 = hh
**
**	Pour le "minus"
** 	Si '-' est présentm alors minus = 1, sinon 0 :D
*/

typedef struct	s_flag
{
	char	buffer[BUFF + 1];
	va_list ap;
	size_t buffer_index;
	size_t str_index;
	char	type;
	char	intflags;
	int		precision;
	int		minsize;
	char	minus;
	char	L;
}				t_flag;

void			*ft_memset(void *s, int c, size_t n);
void			*ft_bzero(void *s, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strdup(const char *s);
size_t			ft_strlen(const char *s);
char			*ft_itoa(int n);
int				ft_atoi(char *s, t_flag *all);
 
 char			*ft_ftoa(double n, int p);
char			*ft_itoa_base(int nb, int c, int maj);
char			*ft_itoa_baseh(short nb, int c, int maj);
char			*ft_itoa_basehh(char nb, int c, int maj);
char			*ft_itoa_basel(long nb, int c, int maj);
char			*ft_itoa_basell(long long nb, int c, int maj);
char			*ft_itoa_pointer(size_t nb);
size_t			ft_strcat2(char *s1, char *s2);

void			ft_int_flags(char *ret, t_flag *all);
void			ft_str_flags(char *ret, t_flag *all);

void			get_char(t_flag *flags);
void			get_int(t_flag *flags);
void			get_int_base(t_flag *flags);
void			get_pointer(t_flag *flags);
void			get_string(t_flag *flags);
void			get_pourcent(t_flag *flags);
void			get_float(t_flag *all);

int				ft_printf(const char *str, ...);

#endif
