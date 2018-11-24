/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:18:14 by conoel            #+#    #+#             */
/*   Updated: 2018/11/14 20:07:57 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*end;
	char	*str;
	int		index;

	if (!s)
		return (NULL);
	index = -1;
	if (!(str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	end = str;
	while (s[++index])
		*str++ = f(index, s[index]);
	*str = '\0';
	return (end);
}
