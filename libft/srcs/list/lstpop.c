/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:30:48 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:30:49 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstpop(t_list **list)
{
	t_list *temp;

	if (!list || !*list)
		return ;
	if ((*list)->next)
		(*list)->next->end = (*list)->end;
	temp = (*list)->next;
	free((*list)->content);
	free(*list);
	*list = temp;
}
