/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 11:11:47 by conoel            #+#    #+#             */
/*   Updated: 2018/11/14 20:07:45 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *end;
	char *str;

	if (!s)
		return (NULL);
	if (!(str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (0);
	end = str;
	while (*s)
		*str++ = f(*s++);
	*str = '\0';
	return (end);
}
