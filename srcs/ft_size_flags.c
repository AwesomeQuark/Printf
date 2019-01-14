/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 18:56:53 by conoel            #+#    #+#             */
/*   Updated: 2019/01/07 16:05:14 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_char_flags(char ret, t_flag *all)
{
	size_t i;

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

void		ft_str_flags(char *ret, t_flag *all)
{
	int i;
	int size;

	i = 0;
	ret == NULL ? ft_strcat2("(null)", all) : 0;
	if (ret == NULL)
		return ;
	size = ft_strlen(ret);
	while ((all->precision == -1 || all->precision > size ? size :
			all->precision) < all->minsize && all->minus == 0)
	{
		all->buffer[all->buffer_index++] = all->zero == 1 ? '0' : ' ';
		all->minsize--;
	}
	all->plus == 1 ? all->buffer[all->buffer_index++] = '+' : 0;
	while (i < (all->precision == -1 || all->precision > size ?
			size : all->precision))
		all->buffer[all->buffer_index++] = ret[i++];
	while ((all->precision == -1 || all->precision > size ?
			size : all->precision) < all->minsize && all->minus == 1)
	{
		all->buffer[all->buffer_index++] = ' ';
		all->minsize--;
	}
}
