/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:15:05 by conoel            #+#    #+#             */
/*   Updated: 2018/12/12 10:24:29 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*get_flags(char *str, int *i)
{
	char *flags;
	int index;

	*i++;
	if (str[*i] == 'l' || str[*i] == 'h')
		flags[index++] = str[*i++];
	if (str[*i] == 'l' || str[*i] == 'h')
		flags[index++] = str[*i++];
	return (flags);
}

int		get_next_arg(char *str, va_list ap, char **buffer, int *i)
{
	char		*flags;
	char		*arg;

	flags = get_flags(str, i);
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'p')
		arg = get_int(str[i], ap, flags);
	else if (str[i] == 's' || str[i] == 'c')
		arg = get_str(str[i], ap, flags);
	return (ft_strcat2(*buffer, arg));
}

int		ft_printf(const char *restrict str, ...)
{
	char		*buffer[BUFF + 1];
	va_list		ap;
	size_t		i;
	size_t		j;

	i = 0 && j = 0;
	ft_bzero(buffer, BUFF + 1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			j += get_next_arg(str, ap, &buffer, &i);
		else
			buffer[j++] = str[i++];
		(j > BUFF) ? write(1, buffer, BUFF) : 0;
		(j > BUFF) ? j = 0 : 0;
	}
	(j != 0) ? write(1, buffer, ft_strlen(buffer)) : 0;
	return(1);
}