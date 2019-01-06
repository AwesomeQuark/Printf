/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:34:59 by conoel            #+#    #+#             */
/*   Updated: 2019/01/06 12:16:02 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_size(long long nb, int prec)
{
	int size;

	size = 0;
	nb == 0 && prec != 0 ? size++ : 0;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb > 0 || prec > 0)
	{
		size += 1;
		nb /= 10;
		prec--;
	}
	return (size);
}

void		ft_itoabs(long long nb, t_flag *all)
{
	int		size;
	int		nb_mem;
	int 	i;

	nb_mem = nb;
	size = ft_size(nb, all->precision);
	((all->space == 1 || all->plus == 1) && nb >= 0) ? size++ : 0;
	i = all->minsize > size ? all->minsize - 1 : size - 1;
	while (all->minus && --all->minsize >= size)
		all->buffer[all->buffer_index + i--] = all->zero && all->precision < 0 ? '0' : ' ';
	nb < 0 ? nb *= -1 : 0;
	nb == 0 && all->precision != 0 ? all->buffer[all->buffer_index + i--] = '0' : 0;
	while (nb > 0 || all->precision > 0)
	{
		all->buffer[all->buffer_index + i--] = nb % 10 + '0';
		nb /= 10;
		all->precision--;
	}
	all->space ? all->buffer[all->buffer_index] = ' ' : 0;
	all->plus && !all->zero ? all->buffer[all->buffer_index + i] = '+' : 0;
	all->plus && all->zero ? all->buffer[all->buffer_index] = '+' : 0;
	nb_mem < 0 && !all->zero ? all->buffer[all->buffer_index + i] = '-' : 0;
	nb_mem < 0 && all->zero ? all->buffer[all->buffer_index] = '-' : 0;
	(nb_mem < 0 || all->plus == 1) && !all->zero ? i -= 1 : 0;
	while (!all->minus && --all->minsize >= size)
		all->buffer[all->buffer_index + i--] = all->zero && all->precision < 0 ? '0' : ' ';
	all->buffer_index += ft_strlen(&all->buffer[all->buffer_index]);
}
