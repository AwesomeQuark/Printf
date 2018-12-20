/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:23:13 by conoel            #+#    #+#             */
/*   Updated: 2018/12/20 13:41:06 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_size(size_t nb)
{
	size_t ret;

	ret = 0;
	while (nb > 0)
	{
		ret++;
		nb /= 16;
	}
	return (ret);
}

char			*ft_itoa_pointer(size_t nb)
{
	char	*end;
	size_t	size;

	size = ft_size(nb);
	end = malloc(sizeof(*end) * (size + 1));
	nb == 0 ? end[0] = '0' : 0;
	end[size] = '\0';
	if (nb == 0)
		end[0] = 48;
	while (nb > 0)
	{
		if (nb % 16 <= 9)
			end[--size] = nb % 16 + '0';
		else
			end[--size] = nb % 16 + 'a' - 10;
		nb /= 16;
	}
	return (end);
}
