/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:32:43 by conoel            #+#    #+#             */
/*   Updated: 2018/12/21 18:02:44 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strcat2(char *buffer, char *arg, t_flag *all)
{
	int i;

	i = 1;
	if (arg == NULL || buffer == NULL)
		return ;
	all->buffer_index++;
	while (*arg)
		buffer[all->buffer_index++] = *arg++;
	*buffer = '\0';
}
