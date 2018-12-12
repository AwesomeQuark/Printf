/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:07:50 by conoel            #+#    #+#             */
/*   Updated: 2018/12/12 19:16:32 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "Libft/libft.h"

char	*ft_itoa_base(int nb, int c, int maj);
size_t	ft_strcat2(char *s1, char *s2);

char	*get_char(va_list ap, char *flags);
char	*get_int(va_list ap, char *flags, char maj);
char	*get_pointer(va_list ap, char *flags);
char	*get_string(va_list ap, char *flags);

int		ft_printf(const char *restrict str, ...);

# define BUFF 2048

#endif

