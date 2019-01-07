/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:40:39 by conoel            #+#    #+#             */
/*   Updated: 2019/01/06 19:55:06 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_atoi(char *s, t_flag *all)
{
	long long		total;
	int				signe;

	total = 0;
	I = (s[I] == '.') ? I + 1 : I;
	if (s[I] == '*')
	{
		total = va_arg(all->ap, int);
		if (total < 0)
		{
			total = total * -1;
			all->minus = 1;
		}
		return (total);
	}
	signe = (s[I] == '-') ? -1 : 1;
	I = (s[I] == '-' || s[I] == '+') ? I + 1 : I;
	while (s[I] >= '0' && s[I] <= '9')
	{
		total = total * 10 + s[I++] - '0';
	}
	I--;
	return (total * signe);
}
