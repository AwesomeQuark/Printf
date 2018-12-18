/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 09:15:05 by conoel            #+#    #+#             */
/*   Updated: 2018/12/17 12:28:46 by conoel           ###   ########.fr       */
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
	all->L = 0;
}

static void	parse_flags(t_flag *all, char *str)
{
	while (((str[I] >= '0' && str[I] <= '9') || str[I] == 'd' ||
str[I] == 'i' || str[I] == 'o' || str[I] == 'u' || str[I] == 'x' ||
str[I] == 'X' || str[I] == 'c' || str[I] == 's' || str[I] == 'p' ||
str[I] == 'l' || str[I] == 'h' || str[I] == 'f' || str[I] == '%' ||
str[I] == '.' || str[I] == '-') && all->type == 0)
	{
		I++;
		if (str[I] == 'd' || str[I] == 'i' || str[I] == 'o' || str[I] == 'u' ||
str[I] == 'x' || str[I] == 'X' || str[I] == 'c' || str[I] == 's' ||
str[I] == 'p' || str[I] == 'f' || str[I] == '%')
			all->type = str[I];
		else if (str[I] == 'l')
			all->intflags = all->intflags == 0 ? 1 : 2;
		else if (str[I] == 'h')
			all->intflags = all->intflags == 0 ? 3 : 4;
		else if (str[I] == 'L')
			all->L = 1;
		else if (str[I] == '.')
			all->precision = ft_atoi(str, all);
		else if ((str[I] >= '0' && str[I] <= '9'))
			all->minsize = ft_atoi(str, all);
		else if (str[I] == '-')
			all->minus = 1;
	}
}

static int	get_next_arg(t_flag *all, char *str)
{
	init(all, 0);
	parse_flags(all, str);
	all->type == 'd' || all->type == 'i' || all->type == 'u' ? get_int(all) : 0;
	all->type == 'o' || all->type == 'x' || all->type == 'X' ? get_int_base(all) : 0;
	all->type == 'c' ? get_char(all) : 0;
	all->type == 'p' ? get_pointer(all) : 0;
	all->type == 's' ? get_string(all) : 0;
	all->type == 'f' ? get_float(all) : 0;
	all->type == '%' ? get_pourcent(all) : 0;
	all->type == 0 ? I -= 1 : 0;
	return(0);
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
	(all.buffer_index != 0) ? write(1, all.buffer, ft_strlen(all.buffer)) : 0;
	va_end(all.ap);
	return (all.buffer_index);
}
