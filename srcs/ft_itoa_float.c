/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:34:16 by conoel            #+#    #+#             */
/*   Updated: 2018/12/20 17:32:47 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char			*ft_insertdot(char *str, int prec)
{
	size_t		index;
	char		tmp;
	char		tmp2;

	index = ft_strlen(str) - prec;
	tmp = str[index];
	str[index] = '.';
	while (--prec)
	{
		tmp2 = str[++index];
		str[index] = tmp;
		tmp = str[++index];
		str[index] = tmp2;
	}
	str[ft_strlen(str) - 1] = '\0';
	return (str);
}

static long long	ft_pow(long double num, int pow)
{
	while (pow-- > 0)
		num *= 10;
	return ((long long)num);
}

char				*ft_ftoa(long double num, int prec)
{
	long long	nb;
	char		*end;

	prec = prec < 0 ? 7 : prec + 1;
	nb = ft_pow(num, prec);
	if (nb % 10 >= 5)
		nb += 10;
	end = ft_itoa_base_signed(nb, 10, 0);
	ft_insertdot(end, prec);
	return (end);
}
