/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:54:40 by conoel            #+#    #+#             */
/*   Updated: 2018/12/21 14:19:17 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	printer(char *ret, t_flag *all)
{
	if (all->plus != 0 && all->type != 'u' && ret[0] != '-')
		all->buffer[all->buffer_index++] = '+';
	else if (all->space != 0 && all->type != 'u' && ret[0] != '-')
		all->buffer[all->buffer_index++] = ' ';
	if (all->hash == 1 && (all->type == 'x' || all->type == 'X') &&
			(ret[0] != 0 && ft_strlen(ret) != 1) && all->zero == 0)
		ft_strcat2(all->buffer, all->type == 'x' ? "0x" : "0X", all);
	if (all->hash == 1 && all->type == 'o')
		all->buffer[all->buffer_index++] = '0';
	ft_strcat2(all->buffer, ret, all);
}

void		ft_int_flags(char *ret, t_flag *all)
{
	int size;

	if (ret[0] == '0' && all->precision == 0) 
		ret[0] = '\0';
	size = ft_strlen(ret);
	all->hash == 1 && all->type != 'o' ? all->minsize -= 2 : 0;
	all->hash == 1 && all->type == 'o' ? all->minsize -= 1 : 0;
	if (all->hash == 1 && (all->type == 'x' || all->type == 'X') && (ret[0] != 0
			&& ft_strlen(ret) != 1) && all->zero == 1)
		ft_strcat2(all->buffer, all->type == 'x' ? "0x" : "0X", all);
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
	if (all->minus == 0 && all->type != 'o')
		printer(ret, all);
}

void		ft_str_flags(char *ret, t_flag *all)
{
	int i;

	i = 0;
	if (ret == NULL)
	{
		ft_strcat2(all->buffer, "(null)", all);
		return ;
	}
	while ((all->precision == -1 || all->precision > (int)ft_strlen(ret) ?
	(int)ft_strlen(ret) : all->precision) < all->minsize && all->minus == 0)
	{
		all->buffer[all->buffer_index++] = all->zero == 1 ? '0' : ' ';
		all->minsize--;
	}
	all->plus == 1 ? all->buffer[all->buffer_index++] = '+' : 0;
	while (i < (all->precision == -1 || all->precision > (int)ft_strlen(ret) ?
			(int)ft_strlen(ret) : all->precision))
		 all->buffer[all->buffer_index++] = ret[i++];
	while ((all->precision == -1 || all->precision > (int)ft_strlen(ret) ?
	(int)ft_strlen(ret) : all->precision) < all->minsize && all->minus == 1)
	{
		all->buffer[all->buffer_index++] = ' ';
		all->minsize--;
	}
}

void		ft_char_flags(char  ret, t_flag *all)
{
	int i;

	i = 0;
	while (1 < all->minsize && all->minus == 0)
	{
		all->buffer[all->buffer_index++] = all->zero == 1 ? '0' : ' ';
		all->minsize--;
	}
	all->plus == 1 ? all->buffer[all->buffer_index++] = '+' : 0;
	all->buffer[all->buffer_index++] = ret;
	while (1 < all->minsize && all->minus == 1)
	{
		all->buffer[all->buffer_index++] = ' ';
		all->minsize--;
	}
}
