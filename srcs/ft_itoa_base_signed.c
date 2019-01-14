/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_signed.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 16:05:58 by conoel            #+#    #+#             */
/*   Updated: 2019/01/14 15:54:11 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int ft_size(long long nb, int prec)
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

static void printer(long long nb, char *tmp, int *i, t_flag *all)
{
	long long nb_mem;
	int prec;

	prec = all->precision;
	nb_mem = nb;
	nb < 0 ? nb *= -1 : 0;
	nb == 0 && all->precision != 0 && all->minsize == 0 ? tmp[(*i)--] = '0' : 0;
	while (nb > 0 || prec > 0)
	{
		tmp[(*i)--] = nb % 10 + '0';
		nb /= 10;
		prec--;
	}
	all->space ? tmp[0] = ' ' : 0;
	all->plus && !all->zero ? tmp[*i] = '+' : 0;
	nb_mem < 0 && !all->zero ? tmp[*i] = '-' : 0;
	(nb_mem < 0 || all->plus == 1) &&!all->zero ? (*i) -= 1 : 0;
}

void ft_itoabs(long long nb, t_flag *all)
{
	char tmp[all->minsize > ft_size(nb, all->precision) ? all->minsize + 1 : ft_size(nb, all->precision) + 1];
	int size;
	long long nb_mem;
	int i;
	int j;

	nb_mem = nb;
	j = all->minsize;
	size = ft_size(nb, all->precision);
	ft_bzero(tmp, all->minsize > size ? all->minsize + 1 : size + 1);
	((all->space == 1 || all->plus == 1) && nb >= 0) ? size++ : 0;
	i = all->minsize > size ? all->minsize - 1 : size - 1;
	nb == 0 && all->precision != 0 && all->minsize != 0 && all->minus ? tmp[i--] = ' ' : 0;
	while (all->minus && --j >= size)
		tmp[i--] = all->zero && all->precision < 0 ? '0' : ' ';
	printer(nb, tmp, &i, all);
	while (!all->minus && --j >= size)
		tmp[i--] = all->zero && all->precision < 0 ? '0' : ' ';
	nb == 0 && all->precision != 0 && all->minsize != 0 && !all->minus ? tmp[i--] = ' ' : 0;
	all->plus && all->zero ? tmp[0] = '+' : 0;
	nb_mem < 0 && all->zero ? tmp[0] = '-' : 0;
	ft_strcat2(tmp, all);
}