/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:45:48 by conoel            #+#    #+#             */
/*   Updated: 2018/11/24 17:41:49 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		get_argc(const char *str)
{
	size_t 	i;
	int		tot;

	tot = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			tot++;
		i++;
	}
	return (tot);
}

int		ft_printf(const char *restrict str, ...)
{
	va_list	ap;
	size_t	i;
	int		argc;

	i = 0;
	argc = get_argc(str);
	va_start(ap, str);
	while (i++ < argc)
		printf("%d", va_arg(ap, int));
	return (1);
}*/

char	*get_right_function(const char *str, va_list ap)
{
	if (*str == 'd')
		return (ft_itoa(va_arg(ap, int)));
	else if (*str == 's')
		return (va_arg(ap, char *));
	else
		ft_putstr_fd("Error : Wrong char following \'%\' !\n", 2);
		return (NULL);
}

int			ft_printf(const char *restrict str, ...)
{
	char	buffer[BUFF + 1];
	va_list	ap;
	size_t	i;
	size_t	j;
	int		tmp;

	i = 0;
	j = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
			j += ft_strcat2(buffer, get_right_function(&(str[++i]), ap));
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
	return(1);
}
