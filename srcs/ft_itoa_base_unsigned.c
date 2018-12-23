/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:54:22 by conoel            #+#    #+#             */
/*   Updated: 2018/12/23 18:53:42 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_size(unsigned long long nb, int c, int prec, t_flag *all)
{
	size_t ret;

	ret = 0;
	nb == 0 && (prec != 0  || all->type == 'o') ? ret++ : 0;
	(all->type == 'X' || all->type == 'x') && all->hash == 1 ? ret += 2 : 0;
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
	size = ft_size(nb, c, all->precision, all);
	end = malloc(sizeof(*end) * (size + 1));
	end[size] = '\0';
	nb == 0 && all->precision != 0 ? end[0] = '0' : 0;
	(all->type == 'X' || all->type == 'x') && all->hash == 1 && nb > 0 ?
			end[0] = '0' : 0;
	(all->type == 'X' || all->type == 'x') && all->hash == 1 && nb > 0 ?
			end[1] = all->type : 0;
	all->type == 'o' && all->hash == 1 ? end[0] = '0' : 0;
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
