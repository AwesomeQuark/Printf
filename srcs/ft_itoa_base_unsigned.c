/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:54:22 by conoel            #+#    #+#             */
/*   Updated: 2018/12/23 21:56:25 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		get_base(int type, int *base)
{
	if (type == 'x' || type == 'X')
		*base = 16;
	else if (type == 'o')
		*base = 8;
	else
		*base = 10;
}

static int		ft_size(unsigned long long nb, int base, int prec, t_flag *all)
{
	int size;

	size = 0;
	nb == 0 && (prec != 0  || all->type == 'o') ? size += 1 : 0;
	(all->type == 'X' || all->type == 'x') && all->hash == 1 ? size += 2 : 0;
	while (nb > 0 || prec > 0)
	{
		size += 1;
		nb /= base;
		prec--;
	}
	return (size);
}

void		ft_itoabu(unsigned long long nb, t_flag *all)
{
	int		size;
	int		base;
	int 	i;

	get_base(all->type, &base);
	size = ft_size(nb, base, all->precision, all);
	size = size - 1 > all->precision ? size : all->precision;
	i = all->minsize > size ? all->minsize - 1 : size - 1;
	while (all->minus == 1 && --all->minsize > size)
		all->buffer[all->buffer_index + i--] = all->zero && all->precision < 0 ? '0' : ' ';
	nb == 0 && all->precision != 0 ? all->buffer[all->buffer_index + i--] = '0' : 0;
	all->type == 'o' && all->hash == 1 ? all->buffer[all->buffer_index + i--] = '0' : 0;
	while (nb > 0 || all->precision > 0)
	{
		if (nb % base <= 9)
			all->buffer[all->buffer_index + i--] = nb % base + '0';
		else
			all->buffer[all->buffer_index + i--] = nb % base + (all->type == 'X' ? 'A' : 'a') - 10;
		nb /= base;
		all->precision--;
	}
	(all->type == 'X' || all->type == 'x') && all->hash == 1 ? all->buffer[all->buffer_index + i--] = all->type : 0;
	(all->type == 'X' || all->type == 'x') && all->hash == 1 ? all->buffer[all->buffer_index + i--] = '0' : 0;
	while (all->minus == 1 && --all->minsize + 1 > size)
		all->buffer[all->buffer_index + i--] = all->zero && all->precision < 0 ? '0' : ' ';
	all->buffer_index += ft_strlen(&all->buffer[all->buffer_index + ++i]);
}
