/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:34:16 by conoel            #+#    #+#             */
/*   Updated: 2018/12/18 12:13:36 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_size(long number, int power, int precision, int *size)
{
	int save;

	save = number;
	while (number > 0)
	{
		number /= 10;
		*size += 1;
	}
	if ((power + 1) < *size)
		*size += 1;
	if (precision < *size - (power + 1))
	{
		*size = precision + (power + 1) + 1;
		while (*size - (power++ + 1) > precision)
			save = save / 10;
		return (save);
	}
	*size += 1;
	return (save);
}

char			*ft_ftoa(double n, int p)
{
	long long	number;
	int		power;
	int		size;
	char	*end;

	number = (long)n >> 52;
	power = (long)n >> 11;
	number = ft_size(number, power, p, &size);
	printf("%lld %d %f\n", number, power, n);
	if (!(end = malloc(sizeof end * size)))
		return (NULL);
	while (number > 0)
	{
		end[--size] = (number % 10) + '0';
		number /= 10;
		if (size == power + 2)
			end[--size] = '.';
	}
	return (end);
}
