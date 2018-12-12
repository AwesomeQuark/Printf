/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:15:05 by conoel            #+#    #+#             */
/*   Updated: 2018/12/12 19:23:13 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*make_string(char type, va_list ap, char *flags)
{
	if (type == 'c')
		return (get_char(ap, flags));
	else if (type == 'd' || type == 'i' || type == 'o' || type == 'u' || type == 'x' || type == 'X')
		return (get_int(ap, flags, type));
	else if (type == 'p')
		return (get_pointer(ap, flags));
	else if (type == 's')
		return (get_string(ap, flags));
	return ("");
}

static char	*get_flags(char *str, int *i)
{
	char *flags;
	int index;

	*i = *i + 1;
	if (str[*i] == 'l' || str[*i] == 'h')
		flags[index++] = str[*i++];
	if (str[*i] == 'l' || str[*i] == 'h')
		flags[index++] = str[*i++];
	return (flags);
}

static int	get_next_arg(char *str, va_list ap, char *buffer, int *i)
{
	char		*flags;
	char		*arg;

	flags = get_flags(str, i);
	if (str[*i] == 'd' || str[*i] == 'i' || str[*i] == 'o' || str[*i] == 'u' || str[*i] == 'x' || str[*i] == 'X' || str[*i] == 'p' || str[*i] == 's' || str[*i] == 'c')
		arg = make_string(str[*i], ap, flags);
	else
		arg = "";
	return (ft_strcat2(buffer, arg));
}

int	ft_printf(const char *restrict str, ...)
{
	char		buffer[BUFF + 1];
	va_list		ap;
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	ft_bzero(buffer, BUFF + 1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			j += get_next_arg((char *)str, ap, buffer, (int *)&i);
		else
			buffer[j++] = str[i];
		i++;
		(j > BUFF) ? write(1, buffer, BUFF) : 0;
		(j > BUFF) ? j = 0 : 0;
	}
	(j != 0) ? write(1, buffer, ft_strlen(buffer)) : 0;
	return(1);
}