/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:54:22 by conoel            #+#    #+#             */
/*   Updated: 2018/12/21 17:58:16 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_size(unsigned long long nb, int c, int prec)
{
	size_t ret;

	ret = 0;
	if (nb == 0)
		ret++;
	while (nb > 0 || prec > 0)
	{
		ret++;
		nb /= c;
		prec--;
	}
	return (ret);
}

char			*ft_itoabu(unsigned long long nb, t_flag *all)
{
	char	*end;
	size_t	size;
	int		c;

	c = (all->type == 'x' || all->type == 'X') ? 16 : 8;
	c = all->type == 'u' ? 10 : c;
	size = ft_size(nb, c, all->precision);
	end = malloc(sizeof(*end) * (size + 1));
	nb == 0 ? end[0] = '0' : 0;
	end[size] = '\0';
	if (nb == 0)
		end[0] = '0';
	while (nb > 0 || all->precision > 0)
	{
		if (nb % c <= 9)
			end[--size] = nb % c + '0';
		else
			end[--size] = nb % c + (all->type == 'X' ? 'A' : 'a') - 10;
		nb /= c;
		all->precision--;
	}
	return (end);
}
