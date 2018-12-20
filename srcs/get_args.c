/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:10:19 by conoel            #+#    #+#             */
/*   Updated: 2018/12/20 13:33:40 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_int_base(t_flag *all)
{
	int		base;
	int		maj;
	char	*ret;

	maj = (all->type == 'X') ? 1 : 0;
	base = (all->type == 'x' || all->type == 'X') ? 16 : 8;
	base = all->type == 'u' ? 10 : base;
	if (all->intflags == 1)
		ret = ft_itoa_base_unsigned((unsigned long)va_arg(all->ap,
				unsigned long), base, maj);
	else if (all->intflags == 2)
		ret = ft_itoa_base_unsigned((unsigned long long)va_arg(all->ap,
				unsigned long long), base, maj);
	else if (all->intflags == 3)
		ret = ft_itoa_base_unsigned((unsigned short)va_arg(all->ap,
				unsigned int), base, maj);
	else if (all->intflags == 4)
		ret = ft_itoa_base_unsigned((unsigned char)va_arg(all->ap,
				unsigned int), base, maj);
	else
		ret = ft_itoa_base_unsigned(va_arg(all->ap, unsigned int), base, maj);
	ft_int_flags(ret, all);
	if (ret)
		free(ret);
}

void	get_int(t_flag *all)
{
	char	*ret;

	if (all->intflags == 1)
		ret = ft_itoa_base_signed((long)va_arg(all->ap, long), 10, 0);
	else if (all->intflags == 2)
		ret = ft_itoa_base_signed((long long)va_arg(all->ap, long long), 10, 0);
	else if (all->intflags == 3)
		ret = ft_itoa_base_signed((short)va_arg(all->ap, unsigned int), 10, 0);
	else if (all->intflags == 4)
		ret = ft_itoa_base_signed((char)va_arg(all->ap, unsigned int), 10, 0);
	else
		ret = ft_itoa_base_signed((int)va_arg(all->ap, unsigned int), 10, 0);
	ft_int_flags(ret, all);
	if (ret)
		free(ret);
}

void	get_pointer(t_flag *all)
{
	char	*ret;

	ret = ft_itoa_pointer((size_t)va_arg(all->ap, void *));
	all->buffer_index += ft_strcat2(all->buffer, "0x");
	all->buffer_index += ft_strcat2(all->buffer, ret);
	if (ret)
		free(ret);
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

	nb = ft_ftoa(va_arg(all->ap, double), all->precision);
	all->buffer_index += ft_strcat2(all->buffer, nb);
	free(nb);
}
