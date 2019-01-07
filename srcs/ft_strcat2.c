/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:32:43 by conoel            #+#    #+#             */
/*   Updated: 2019/01/07 15:54:45 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strcat2(char *arg, t_flag *all)
{
	if (arg == NULL)
		return ;
	while (*arg)
		all->buffer[all->buffer_index++] = *arg++;
}
