/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:54:22 by conoel            #+#    #+#             */
/*   Updated: 2018/12/20 18:37:54 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_size(unsigned long long nb, int c)
{
	size_t ret;

	ret = 0;
	if (nb == 0)
		ret++;
	while (nb > 0)
	{
		ret++;
		nb /= c;
	}
	return (ret);
}

char			*ft_itoa_base_unsigned(unsigned long long nb, int c, int maj)
{
	char	*end;
	size_t	size;

	size = ft_size(nb, c);
	end = malloc(sizeof(*end) * (size + 1));
	nb == 0 ? end[0] = '0' : 0;
	end[size] = '\0';
	if (nb == 0)
		end[0] = '0';
	while (nb > 0)
	{
		if (nb % c <= 9)
			end[--size] = nb % c + '0';
		else
			end[--size] = nb % c + (maj == 1 ? 'A' : 'a') - 10;
		nb /= c;
	}
	return (end);
}
