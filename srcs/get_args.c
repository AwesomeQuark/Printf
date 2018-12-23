/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:10:19 by conoel            #+#    #+#             */
/*   Updated: 2018/12/23 18:54:35 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_int_base(t_flag *all)
{
	char	*ret;

	if (all->intflags == 1)
		ret = ft_itoabu((unsigned long)va_arg(all->ap, unsigned long), all);
	else if (all->intflags == 2)
		ret = ft_itoabu((unsigned long long)va_arg(all->ap, ULL), all);
	else if (all->intflags == 3)
		ret = ft_itoabu((unsigned short)va_arg(all->ap, unsigned int), all);
	else if (all->intflags == 4)
		ret = ft_itoabu((unsigned char)va_arg(all->ap, unsigned int), all);
	else
		ret = ft_itoabu(va_arg(all->ap, unsigned int), all);
	print(ret, all);
}

void	get_int(t_flag *all)
{
	char	*ret;

	if (all->intflags == 1)
		ret = ft_itoa_base_signed((long)va_arg(all->ap, long), all);
	else if (all->intflags == 2)
		ret = ft_itoa_base_signed((long long)va_arg(all->ap, long long), all);
	else if (all->intflags == 3)
		ret = ft_itoa_base_signed((short)va_arg(all->ap, unsigned int), all);
	else if (all->intflags == 4)
		ret = ft_itoa_base_signed((char)va_arg(all->ap, unsigned int), all);
	else
		ret = ft_itoa_base_signed((int)va_arg(all->ap, unsigned int), all);
	print(ret, all);
}

void	get_pointer(t_flag *all)
{
	size_t	nb;
	size_t	index;

	nb = va_arg(all->ap, size_t);
	index = 12;
	all->buffer[all->buffer_index++] = '0';
	all->buffer[all->buffer_index++] = 'x';
	if (nb == 0)
		all->buffer[all->buffer_index++] = 48;
	while (index--)
	{
		if (nb % 16 <= 9)
			all->buffer[all->buffer_index + index] = nb % 16 + '0';
		else
			all->buffer[all->buffer_index + index] = nb % 16 + 'a' - 10;
		nb /= 16;
	}
	all->buffer_index += 12;
}

void	get_pourcent(t_flag *all)
{
	int		size;

	size = 1;
	if (all->minus == 1)
		all->buffer[all->buffer_index++] = '%';
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
		all->buffer[all->buffer_index++] = '%';
}

void	get_float(t_flag *all)
{
	char *nb;

	if (all->l == 1)
		nb = ft_ftoa(va_arg(all->ap, long double), all);
	else
		nb = ft_ftoa(va_arg(all->ap, double), all);
	ft_strcat2(nb, all);
	free(nb);
}
