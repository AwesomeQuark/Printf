/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_converters.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 11:43:59 by conoel            #+#    #+#             */
/*   Updated: 2019/01/30 12:51:24 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_errno(t_flag *all)
{
	char	*tmp;

	tmp = strerror(errno);
	ft_strcat2(tmp, all);
	all->space = 0;
}

void	get_charwriten(t_flag *all)
{
	int		*ptr;

	ptr = va_arg(all->ap, int *);
	*ptr = all->buffer_index;
}
