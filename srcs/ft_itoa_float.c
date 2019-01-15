/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:34:16 by conoel            #+#    #+#             */
/*   Updated: 2019/01/15 10:14:30 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_size(long long nb)
{
	int size;

	size = 0;
	while (nb > 0)
	{
		size += 1;
		nb /= 10;
	}
	return (size);
}

static long long	ft_pow(long double num, int pow)
{
	while (pow-- > 0)
		num *= 10;
	(long long)num % 10 >= 5 ? num += 10 : 0;
	num /= 10;
	return ((long long)num);
}

void				printer(t_flag *all, long long nb, int size, int point_i)
{
	char	tmp[size + 1];
	int		minsize;

	ft_bzero(tmp, size + 1);
	minsize = all->minsize - ft_size(nb);
	while (all->minus == 1 && minsize-- > 0)
		tmp[--size] = all->zero ? '0' : ' ';
	while (nb > 0)
	{
		tmp[--size] = nb % 10 + 48;
		nb /= 10;
		size == point_i ? tmp[--size] = '.' : 0;
	}
	while (all->minus == 0 && minsize-- > 0)
		tmp[--size] = all->zero ? '0' : ' ';
	ft_strcat2(tmp, all);
}

void				ft_ftoa(long double num, t_flag *all)
{
	long long	nb;
	int			size;
	int			point_i;

	all->precision = all->precision < 0 ? 7 : all->precision + 1;
	nb = ft_pow(num, all->precision);
	size = ft_size(nb);
	point_i = ft_size(num);
	point_i += all->minsize > size && all->minus == 0 ? all->minsize - size : 0;
	size = size > all->minsize ? size : all->minsize;
	printer(all, nb, size, point_i);
}