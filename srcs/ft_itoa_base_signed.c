/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:34:59 by conoel            #+#    #+#             */
/*   Updated: 2018/12/20 13:52:52 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_size(long long nb, int c)
{
	size_t ret;

	ret = 0;
	if (nb < 0)
	{
		ret++;
		nb = nb * -1;
	}
	if (nb == 0)
		ret++;
	while (nb > 0)
	{
		ret++;
		nb /= c;
	}
	return (ret);
}

char			*ft_itoa_base_signed(long long nb, int c, int maj)
{
	char	*end;
	size_t	size;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(nb, c);
	end = malloc(sizeof(*end) * (size + 1));
	nb == 0 ? end[0] = '0' : 0;
	end[size] = '\0';
	if (nb < 0)
	{
		end[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		end[0] = 48;
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
