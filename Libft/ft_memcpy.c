/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:42:40 by conoel            #+#    #+#             */
/*   Updated: 2018/11/11 14:25:05 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *dst1;
	char *src1;

	dst1 = (char *)dst;
	src1 = (char *)src;
	while ((int)--n >= 0)
		*(dst1 + n) = *(src1 + n);
	return (dst1);
}
