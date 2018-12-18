/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 18:10:19 by conoel            #+#    #+#             */
/*   Updated: 2018/12/16 18:02:23 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void 	get_char(t_flag *all)
{
	char a;
	char maj[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char min[27] = "abcdefghijklmnopqrstuvwxyz";

	a = (char)va_arg(all->ap, int);
	if (a < 90 && a > 65)
		a = maj[a - 65];
	else if (a < 122 && a > 97)
		a = min[a - 97];
	all->buffer[all->buffer_index++] = a;
}

void	get_int_base(t_flag *all)
{
	int base;
	int maj;
	char *ret;
 
	maj = (all->type == 'X') ? 1 : 0;
	base = (all->type == 'x' || all->type == 'X') ? 16 : 8;
	if (all->intflags == 1)
		ret = ft_itoa_basel((long)va_arg(all->ap, unsigned int), base, maj);
	else if (all->intflags == 2)
		ret = ft_itoa_basell((long long)va_arg(all->ap, unsigned int), base, maj);
	else if (all->intflags == 3)
		ret = ft_itoa_baseh((short)va_arg(all->ap, unsigned int), base, maj);
	else if (all->intflags == 4)
		ret = ft_itoa_basehh((char)va_arg(all->ap, unsigned int), base, maj);
	else
		ret = ft_itoa_base(va_arg(all->ap, unsigned int), base, maj);
	if (all->precision != 0)
		ft_int_flags(ret, all);
	if (ret)
		free(ret);
}

void	get_int(t_flag *all)
{
	char *ret;

	if (all->intflags == 1)
		ret = ft_itoa_basel((long long)va_arg(all->ap, unsigned int), 10, 0);
	else if (all->intflags == 2)
		ret = ft_itoa_basell((long)va_arg(all->ap, unsigned int), 10, 0);
	else if (all->intflags == 3)
		ret = ft_itoa_baseh((short)va_arg(all->ap, unsigned int), 10, 0);
	else if (all->intflags == 4)
		ret = ft_itoa_basehh((char)va_arg(all->ap, unsigned int), 10, 0);
	else
		ret = ft_itoa_base(va_arg(all->ap, unsigned int), 10, 0);
	if (all->precision != 0)
		ft_int_flags(ret, all);
	if (ret)
		free(ret);
}

void	get_pointer(t_flag *all)
{
	char *ret;
	
	ret = ft_itoa_pointer((size_t)va_arg(all->ap, void *));
	all->buffer_index += ft_strcat2(all->buffer, "0x");
	all->buffer_index += ft_strcat2(all->buffer, ret);
	if (ret)
		free(ret);
}

void	get_string(t_flag *all)
{
	ft_str_flags(va_arg(all->ap, char *), all);
}