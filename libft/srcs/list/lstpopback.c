/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpopback.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:30:45 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:30:46 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void		ft_lstpopback(t_list **list)
{
	register t_list	*iter;

	if (!list || !*list)
		return ;
	if (!(*list)->next)
		ft_lstpop(list);
	else
	{
		iter = *list;
		while (iter->next != (*list)->end)
			iter = iter->next;
		free(iter->next->content);
		free(iter->next);
		iter->next = NULL;
		(*list)->end = iter;
	}
}
