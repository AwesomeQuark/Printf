/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:53:38 by conoel            #+#    #+#             */
/*   Updated: 2018/11/14 19:13:50 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_slen(char *s, int *i, char c)
{
	int p;
	int size;

	p = *i;
	size = 0;
	while (c == (s[p]))
		p++;
	if (c != s[p] && s[p] != '\0')
	{
		while (c != (s[p]) && s[p] != '\0')
		{
			p++;
			size++;
		}
		*i = p;
		return (size);
	}
	p++;
	return (0);
}

static int		ft_nb_words(char *s, char c)
{
	int i;
	int nb_word;
	int word;

	i = 0;
	nb_word = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (c != s[i])
			word = 1;
		if (word == 1 && c == s[i])
		{
			nb_word++;
			word = 0;
		}
		i++;
	}
	if (word == 1)
		nb_word++;
	return (nb_word);
}

static char		**fill_end(char *s, char **end, int nb_word, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (j < nb_word)
	{
		while (c == (s[i]))
			i++;
		if (c != (s[i]) && s[i] != '\0')
		{
			k = 0;
			while (c != (s[i]) && s[i] != '\0')
				end[j][k++] = s[i++];
		}
		end[j][k] = '\0';
		j++;
		i++;
	}
	return (end);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**end;
	int		i;
	int		j;
	int		nb_word;
	int		size;

	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	nb_word = ft_nb_words((char *)s, c);
	if (!(end = (char**)malloc(sizeof(char*) * (nb_word + 1))))
		return (0);
	while (j < nb_word)
	{
		size = ft_slen((char *)s, &i, c);
		if (!(end[j] = (char*)malloc(sizeof(char) * (size + 1))))
			return (0);
		j++;
	}
	end[nb_word] = 0;
	end = fill_end((char *)s, end, nb_word, c);
	return (end);
}
