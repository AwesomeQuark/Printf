/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:54:40 by conoel            #+#    #+#             */
/*   Updated: 2018/12/16 15:47:57 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_int_flags(char *ret, t_flag *all)
{
	int size;

	size = ft_strlen(ret);
	if(all->minus == 1)
		all->buffer_index += ft_strcat2(all->buffer, ret);
	while (all->precision > size)
	{
		size++;
		all->buffer_index += ft_strcat2(all->buffer, "0");
	}
	while (all->minsize > size)
	{
		size++;
		all->buffer_index += ft_strcat2(all->buffer, " ");
	}
	if (all->minus == 0)
		all->buffer_index += ft_strcat2(all->buffer, ret);
}

void	ft_str_flags(char *ret, t_flag *all)
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