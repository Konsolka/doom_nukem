/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpurge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:30:48 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:31:46 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstpurge(t_list **list)
{
	register t_list *iter;
	register t_list *temp;

	if (!list || !*list)
		return ;
	iter = *list;
	while (iter)
	{
		temp = iter->next;
		free(iter->content);
		free(iter);
		iter = temp;
	}
	*list = NULL;
}
