/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 19:23:13 by conoel            #+#    #+#             */
/*   Updated: 2018/12/16 18:17:55 by conoel           ###   ########.fr       */
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

static char		ft_char(int c)
{
	char str[16] = "0123456789abcdef";
	return (str[c]);
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
		end[--size] = ft_char(nb % 16);
		nb /= 16;
	}
	return (end);
}