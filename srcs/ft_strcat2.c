/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:32:43 by conoel            #+#    #+#             */
/*   Updated: 2018/12/20 13:34:17 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t			ft_strcat2(char *buffer, char *arg)
{
	size_t	size;

	if (arg == NULL || buffer == NULL)
		return (0);
	size = 0;
	while (*buffer)
		buffer++;
	*buffer = *arg;
	while (*arg)
	{
		*buffer++ = *arg++;
		size++;
	}
	*buffer = '\0';
	return (size);
}
