/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:34:16 by conoel            #+#    #+#             */
/*   Updated: 2018/12/17 14:02:39 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_size(int n)
{
	int size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	while (n > 1)
	{
		n /= 10;
		size++;
	}
	return (size + 1);
}

char			*ft_ftoa(float n, int p)
{
	char	*end;
	int		size;

	size = ft_size((int)n);
	if (!(end = (char *)malloc(sizeof(char) * (size-- + (p > 3 ? p : 3)))
		return (0);
	end[size--] = '.';
	if (n < 0)
	{
		end[0] = '-';
		n *= -1;
	}
	if (n == 0)
		end[0] = 48;
	while (n)
	{
		end[size--] = n % 10 + 48;
		n = n / 10;
	}
	return (end);
}
