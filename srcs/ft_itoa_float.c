/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:34:16 by conoel            #+#    #+#             */
/*   Updated: 2019/01/06 22:00:00 by conoel           ###   ########.fr       */
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
	//num /= 10;
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
	size = ft_size(nb);
	size_mem = size;
	point_i += all->minsize > size && all->minus == 0 ? all->minsize - size + 1 : 0;
	size = size > all->minsize ? size : all->minsize + 1;
	while (all->minus == 1 && all->minsize-- > size_mem)
		all->buffer[all->buffer_index + size--] = all->zero ? '0' : ' ';
	while (nb > 0)
	{
		all->buffer[all->buffer_index + size--] = nb % 10 + 48;
		nb /= 10;
		size == point_i ? all->buffer[all->buffer_index + size--] = '.' : 0;
	}
	while (all->minus == 0 && size > 0)
		all->buffer[all->buffer_index + size--] = all->zero ? '0' : ' ';
	all->buffer_index += size_mem;
}