/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 16:10:10 by conoel            #+#    #+#             */
/*   Updated: 2019/01/28 12:34:28 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	get_size(size_t nb)
{
	int size;

	size = 0;
	nb == 0 ? size++ : 0;
	while (nb > 0)
	{
		size++;
		nb /= 16;
	}
	return (size);
}

static void	printer(size_t nb, t_flag *all)
{
	int		index;
	char	tmp[15];

	ft_bzero(tmp, 15);
	index = get_size(nb) - 1;
	if (nb == 0)
	{
		all->precision == 0 ? ft_strcat2("0x", all) : 0;
		all->precision != 0 ? ft_strcat2("0x0", all) : 0;
		while (all->minsize - 2 > index++ && index < 10)
			ft_charcat2('0', all);
		return ;
	}
	tmp[0] = '0';
	tmp[1] = 'x';
	while (nb > 0)
	{
		if (nb % 16 <= 9)
			tmp[index-- + 2] = nb % 16 + '0';
		else
			tmp[index-- + 2] = nb % 16 + 'a' - 10;
		nb /= 16;
	}
	ft_strcat2(tmp, all);
}

void		ft_ptoa(size_t nb, t_flag *all)
{
	int size;

	size = get_size(nb) + 2;
	while (!all->minus && all->minsize-- > size)
		ft_charcat2(all->zero ? '0' : ' ', all);
	printer(nb, all);
	while (all->minus && all->minsize-- > size)
		ft_charcat2(' ', all);
}
