/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:54:40 by conoel            #+#    #+#             */
/*   Updated: 2018/12/20 13:37:08 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	printer(char *ret, t_flag *all)
{
	if (((all->space == 1 || all->plus == 1) && all->type != 'u')
			&& ret[0] != '-')
		all->buffer[all->buffer_index++] = all->plus == 1 ? '+' : ' ';
	if (all->hash == 1 && (all->type == 'x' || all->type == 'X') &&
			(ret[0] != 0 && ft_strlen(ret) != 1) && all->zero == 0)
		all->buffer_index += ft_strcat2(all->buffer, all->type == 'x' ?
				"0x" : "0X");
	all->buffer_index += ft_strcat2(all->buffer, ret);
}

void		ft_int_flags(char *ret, t_flag *all)
{
	int size;

	size = ft_strlen(ret);
	all->hash == 1 ? all->minsize -= 2 : 0;
	if (all->hash == 1 && (all->type == 'x' || all->type == 'X') && (ret[0] != 0
			&& ft_strlen(ret) != 1) && all->zero == 1)
		all->buffer_index += ft_strcat2(all->buffer, all->type == 'x' ?
				"0x" : "0X");
	if (all->minus == 1)
		printer(ret, all);
	while (all->precision > size)
	{
		size++;
		all->buffer[all->buffer_index++] = '0';
	}
	while (all->minsize > size)
	{
		size++;
		all->buffer[all->buffer_index++] = all->zero ? '0' : ' ';
	}
	if (all->minus == 0)
		printer(ret, all);
}

void		ft_str_flags(char *ret, t_flag *all)
{
	int i;

	i = 0;
	if (ret == NULL)
	{
		all->buffer_index += ft_strcat2(all->buffer, "(null)");
		return ;
	}
	while ((int)ft_strlen(ret) < all->minsize && all->minus == 0)
	{
		all->buffer[all->buffer_index++] = ' ';
		all->minsize--;
	}
	while (i < (all->precision == -1 ? (int)ft_strlen(ret) : all->precision))
		all->buffer[all->buffer_index++] = ret[i++];
	while ((int)ft_strlen(ret) < all->minsize && all->minus == 1)
	{
		all->buffer[all->buffer_index++] = ' ';
		all->minsize--;
	}
}
