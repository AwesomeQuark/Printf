/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:45:48 by conoel            #+#    #+#             */
/*   Updated: 2018/11/23 23:33:39 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

//char	get_right_function(char c)
//{
//}

int		printf(const char *restrict str, ...)
{
	char	*buffer[BUFF + 1]
	
	size_t 	i;
	size_t 	buff_i;

	i = 0;
	buff_i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			get_right_function(str[i + 1]);
		}
		else
			buffer[buff_i++] = str[i];
		i++;
	}
}