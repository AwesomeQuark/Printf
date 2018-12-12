/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:07:50 by conoel            #+#    #+#             */
/*   Updated: 2018/12/11 10:50:12 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include "Libft/libft.h"
# include "functions.c"

char	*ft_itoa(int n);
char	*ft_itoc(int n);
size_t	ft_strcat2(char *s1, char *s2);
char	*get_flags(const char *str);
char	*get_right_function(const char *str, va_list ap, char *flags);
int		ft_printf(const char *restrict str, ...);

# define BUFF 1048

#endif

