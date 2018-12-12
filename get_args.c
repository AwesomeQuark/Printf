/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:23:03 by conoel            #+#    #+#             */
/*   Updated: 2018/12/12 19:36:21 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_char(va_list ap, char *flags)
{
	return (ft_itoa(va_arg(ap, int)));
}

char	*get_int(va_list ap, char *flags, char t)
{
	int b;
 
	b = (t == 'x' || t == 'X') ? 16 : 10;
	if (ft_strcmp("l", flags) == 0)

	else if (ft_strcmp("ll", flags) == 0)

	else if (ft_strcmp("h", flags) == 0)

	else if (ft_strcmp("hh", flags) == 0)
	
	return(ft_itoa_base(va_arg(ap, int), t == 'o' ? 8 : b, (t == 'x') ? 0 : 1));
}

char	*get_pointer(va_list ap, char *flags)
{
	return(ft_itoa_base((unsigned int)va_arg(ap, void *), 16, 1));
}

char	*get_string(va_list ap, char *flags)
{
	return(va_arg(ap, char *));
}