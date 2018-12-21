/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:34:59 by conoel            #+#    #+#             */
/*   Updated: 2018/12/21 20:17:14 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_size(long long nb, int prec, t_flag *all)
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
	all->hash == 1 ? ret++ : 0;
	all->hash == 1 && all->type != 'o' ? ret++ : 0;
	while (nb > 0 || prec > 0)
	{
		ret++;
		nb /= 10;
		prec--;
	}
	return (ret);
}

char			*ft_itoa_base_signed(long long nb, t_flag *all)
{
	char	*end;
	size_t	size;

	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	size = ft_size(nb, all->precision, all);
	end = malloc(sizeof(*end) * (size + 1));
	nb == 0 ? end[0] = '0' : 0;
	end[size] = '\0';
	if (nb < 0)
	{
		end[0] = '-';
		nb = nb * -1;
	}
	nb == 0 ? end[0] = 48 : 0;
	all->hash == 1 ? end[--size] = '0' : 0;
	all->hash == 1 && all->type != 'o' ? end[size--] = 'x' : 0;
	while (nb > 0 || all->precision > 0)
	{
		end[--size] = nb % 10 + '0';
		nb /= 10;
		all->precision--;
	}
	return (end);
}
