/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:04:49 by conoel            #+#    #+#             */
/*   Updated: 2018/11/14 15:55:56 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *temp;
	t_list *all;

	all = *alst;
	*alst = NULL;
	while (all)
	{
		temp = all->next;
		del(all->content, all->content_size);
		free(all);
		all = temp;
	}
}
