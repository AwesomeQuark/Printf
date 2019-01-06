/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:34:16 by conoel            #+#    #+#             */
/*   Updated: 2019/01/06 14:49:00 by conoel           ###   ########.fr       */
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
	return (size + 1);
}

static long long	ft_pow(long double num, int pow)
{
	while (pow-- > 0)
		num *= 10;
	return ((long long)num);
}

void				ft_ftoa(long double num, t_flag *all)
{
	long long	nb;
	int			size;
	int			size_mem;
	int			point_i;

	all->precision = all->precision < 0 ? 7 : all->precision + 1;
	point_i = ft_size(num);
	nb = ft_pow(num, all->precision);
	nb % 10 >= 5 ? nb += 10 : 0;
	nb /= 10;
	size = ft_size(nb);
	size = all->minsize > size ? all->minsize : size;
	size_mem = size;
	while (all->minus == 1 && --all->minsize >= size)
		all->buffer[all->buffer_index + size--] = all->zero && all->precision < 0 ? '0' : ' ';
	while (nb > 0)
	{
		all->buffer[all->buffer_index + size--] = nb % 10 + 48;
		nb /= 10;
		size == point_i ? all->buffer[all->buffer_index + size--] = '.' : 0;
	}
	while (all->minus == 0 && --all->minsize >= size)
		all->buffer[all->buffer_index + size--] = all->zero && all->precision < 0 ? '0' : ' ';
	all->buffer_index += size_mem;
}