/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 16:34:59 by conoel            #+#    #+#             */
/*   Updated: 2018/12/10 17:46:12 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>

size_t		ft_strcat2(char	*s1, char *s2)
{
	size_t	size;

	size = 0;
	while (*s1)
		s1++;
	*s1 = *s2;
	while (*s1)
	{
		s1++;
		s2++;
		size++;
		*s1 = *s2;
	}
	*s1 = '\0';
	return (size);
}

char *ft_itoc(int n)
{
	char *end;

	if (n > 127)
		return ("\0");
	*end = (char)n;
	end[1] = '\0';
	return (end);
}