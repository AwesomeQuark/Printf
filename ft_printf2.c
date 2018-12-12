/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:45:48 by conoel            #+#    #+#             */
/*   Updated: 2018/12/12 09:31:45 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*right_place(const char *str)
{
	while (*str == 'l' || *str == 'h' || *str == 'q')
		str++;
	return ((char *)str);
}

char	*get_flags(const char *str)
{
	char	*flags;
	int		i;

	i = 0;
	while (str[i] == 'l' || str[i] == 'h' || str[i] == 'q')
		i++;
	flags = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] == 'l' || str[i] == 'h' || str[i] == 'q')
	{
		i++;
		flags[i] = str[i];
	}
	return (flags);
}

char	*get_right_function(const char *str, va_list ap, char *flags)
{
	if (*str == 'd' || *str == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (*str == 's')
		return (va_arg(ap, char *));
	else if (*str == 'c')
		return (ft_itoc(va_arg(ap, int)));
	else if (*str == 'p')
		return (ft_itoa((unsigned int)va_arg(ap, void *)));
	ft_putstr_fd("Error : Wrong character following \'%\' !\n", 2);
	return ("");
}

int			ft_printf(const char *restrict str, ...)
{
	char	buffer[BUFF + 1];
	va_list	ap;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	ft_bzero(buffer, BUFF + 1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			j += ft_strcat2(buffer, get_right_function(right_place(&(str[i + 1])), ap, get_flags(&str[i + 1])));
		else
			buffer[j++] = str[i];
		i++;
		if (j > BUFF)
		{
			j = 0;
			write(1, buffer, BUFF);
		}
	}
	if (j != 0)
		write(1, buffer, ft_strlen(buffer));
	return (1);
}
