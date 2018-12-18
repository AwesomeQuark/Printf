/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_baseh.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 19:54:16 by conoel            #+#    #+#             */
/*   Updated: 2018/12/16 18:18:19 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	ft_size(short nb, int c)
{
	size_t ret;

	ret = 0;
	if (nb < 0)
	{
		ret++;
		nb = nb * -1;
	}
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

char			*ft_itoa_baseh(short nb, int c, int maj)
{
	char	*end;
	size_t	size;

	if (nb == -32768)
		return(ft_strdup("-32768"));
	size = ft_size(nb, c);
	end = malloc(sizeof(*end) * (size + 1));
	nb == 0 ? end[0] = '0' : 0;
	end[size] = '\0';
	if (nb < 0)
	{
		end[0] = '-';
		nb = nb * -1;
	}
	if (nb == 0)
		end[0] = 48;
	while (nb > 0)
	{
		end[--size] = maj ? ft_charmaj(nb % c) : ft_char(nb % c);
		nb /= c;
	}
	return (end);
}