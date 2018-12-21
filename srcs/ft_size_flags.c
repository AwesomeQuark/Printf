/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:54:40 by conoel            #+#    #+#             */
/*   Updated: 2018/12/21 18:13:43 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
