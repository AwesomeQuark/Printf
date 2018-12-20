/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:32:43 by conoel            #+#    #+#             */
/*   Updated: 2018/12/20 18:44:53 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strcat2(char *buffer, char *arg, t_flag *all)
{
	if (arg == NULL || buffer == NULL)
		return ;
	while (*buffer)
		buffer++;
	*buffer = *arg;
	while (*arg)
	{
		*buffer++ = *arg++;
		all->buffer_index++;
	}
	*buffer = '\0';
}
