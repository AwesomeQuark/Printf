/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:34:59 by conoel            #+#    #+#             */
/*   Updated: 2018/12/12 19:32:58 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_size(int nb, int c)
{
	size_t ret;

	ret = 0;
	while (nb > 0)
	{
		ret++;
		nb /= c;
	}
	return (ret);
}

static char		ft_char(int c)
{
	char str[16] = "0123456789abcdef";
	return (str[c]);
}

static char		ft_charmaj(int c)
{
	char str[16] = "0123456789ABCDEF";
	return (str[c]);
}

char			*ft_itoa_base(int nb, int c, int maj)
{
	char	*end;
	size_t	size;

	size = ft_size(nb, c);
	end = malloc(sizeof(*end) * (size + 1));
	nb == 0 ? end[0] = '0' : 0;
	while (nb > 0)
	{
		end[--size] = maj ? ft_charmaj(nb % c) : ft_char(nb % c);
		nb /= c;
	}
	return (end);
}