/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:15:05 by conoel            #+#    #+#             */
/*   Updated: 2018/12/21 13:49:45 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	init(t_flag *all, int start)
{
	if (start)
	{
		all->buffer_index = 0;
		all->str_index = 0;
		ft_bzero(all->buffer, BUFF + 1);
	}
	all->intflags = 0;
	all->type = 0;
	all->intflags = 0;
	all->precision = -1;
	all->minsize = 0;
	all->minus = 0;
	all->l = 0;
	all->space = 0;
	all->hash = 0;
	all->plus = 0;
	all->zero = 0;
}

static int	if_norme(char s, int type)
{
	if (type == 1)
	{
		if ((s >= '0' && s <= '9') || s == 'd' || s == 'i' || s == 'o' ||
	s == 'u' || s == 'x' || s == 'X' || s == 'c' || s == 's' || s == 'p' ||
	s == 'l' || s == 'h' || s == 'f' || s == '%' || s == '.' || s == '-' ||
	s == ' ' || s == '+' || s == '#' || s == 'L')
			return (1);
	}
	if (type == 2)
	{
		if (s == 'd' || s == 'i' || s == 'o' || s == 'u' || s == 'x' ||
		s == 'X' || s == 'c' || s == 's' || s == 'p' || s == 'f' || s == '%')
			return (1);
	}
	return (0);
}

static void	parse_flags(t_flag *all, char *str)
{
	while (if_norme(str[I], 1) && all->type == 0)
	{
		I++;
		if_norme(str[I], 2) ? all->type = str[I] : 0;
		if (str[I] == 'l')
			all->intflags = all->intflags == 0 ? 1 : 2;
		if (str[I] == 'h')
			all->intflags = all->intflags == 0 ? 3 : 4;
		str[I] == 'L' ? all->l = 1 : 0;
		str[I] == '0' && str[I - 1] != '-' ? all->zero = 1 : 0;
		str[I] == '-' ? all->minus = 1 : 0;
		str[I] == '+' ? all->plus = 2 : 0;
		str[I] == ' ' ? all->space = 1 : 0;
		str[I] == '#' ? all->hash = 1 : 0;
		str[I] >= '1' && str[I] <= '9' ? all->minsize = ft_atoi(str, all) : 0;
		str[I] == '.' ? all->precision = ft_atoi(str, all) : 0;
	}
}

static int	get_next_arg(t_flag *all, char *str)
{
	init(all, 0);
	parse_flags(all, str);
	all->type == 'd' || all->type == 'i' ? get_int(all) : 0;
	all->type == 'o' || all->type == 'x' || all->type == 'X' || all->type == 'u'
			? get_int_base(all) : 0;
	all->type == 'c' ? ft_char_flags((char)va_arg(all->ap, int), all) : 0;
	all->type == 'p' ? get_pointer(all) : 0;
	all->type == 's' ? ft_str_flags(va_arg(all->ap, char *), all) : 0;
	all->type == 'f' ? get_float(all) : 0;
	all->type == '%' ? get_pourcent(all) : 0;
	all->type == 0 ? I -= 1 : 0;
	return (0);
}

int			ft_printf(const char *str, ...)
{
	t_flag		all;

	init(&all, 1);
	va_start(all.ap, str);
	while (str[all.str_index])
	{
		if (str[all.str_index] == '%')
		{
			get_next_arg(&all, (char *)str);
		}
		else
			all.buffer[all.buffer_index++] = str[all.str_index];
		all.str_index++;
	}
	(all.buffer_index != 0) ? write(1, all.buffer, all.buffer_index) : 0;
	va_end(all.ap);
	return (all.buffer_index);
}
