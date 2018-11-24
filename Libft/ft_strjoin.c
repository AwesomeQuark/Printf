/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 16:41:16 by conoel            #+#    #+#             */
/*   Updated: 2018/11/15 23:10:30 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*end;
	int		index;

	if (!s1 || !s2)
		return (NULL);
	index = 0;
	if (!(end = (char *)malloc(sizeof(char) * (ft_strlen(s1)
	+ ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		end[index++] = *s1++;
	while (*s2)
		end[index++] = *s2++;
	end[index] = '\0';
	return (end);
}
