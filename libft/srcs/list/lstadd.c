/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:30:49 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:30:52 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstadd(t_list **list, t_list *new_elem)
{
	if (list && new_elem)
	{
		new_elem->next = *list;
		*list = new_elem;
		if ((*list)->next)
			(*list)->end = (*list)->next->end;
	}
}
