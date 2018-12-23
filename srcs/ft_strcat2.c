/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:32:43 by conoel            #+#    #+#             */
/*   Updated: 2018/12/23 18:46:52 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strcat2(char *arg, t_flag *all)
{
	size_t i;

	i = 1;
	if (arg == NULL)
		return ;
	while (*arg)
		all->buffer[all->buffer_index++] = *arg++;
}
