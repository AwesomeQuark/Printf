/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_args2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 11:30:11 by conoel            #+#    #+#             */
/*   Updated: 2018/12/18 12:12:00 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	get_pourcent(t_flag *all)
{
	ft_int_flags("%", all);
}

void	get_float(t_flag *all)
{
	char *nb;

//	if (all->L)
//		nb = NULL;//ft_ftoaL(va_arg(all->ap, long double), all->precision);
//	else
	nb = ft_ftoa(va_arg(all->ap, double), all->precision);
	all->buffer_index += ft_strcat2(all->buffer, nb);
	free(nb);
}