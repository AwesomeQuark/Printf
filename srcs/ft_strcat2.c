/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:32:43 by conoel            #+#    #+#             */
/*   Updated: 2018/12/21 11:56:13 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strcat2(char *buffer, char *arg, t_flag *all)
{
	int i;

	i = 1;
	if (arg == NULL || buffer == NULL)
		return ;
	while (*buffer)
		buffer++;
	while (*arg)
	{
		*buffer++ = *arg++;
		all->buffer_index++;
	}
	*buffer = '\0';
}
