/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstextend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:30:46 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:30:46 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_lstextend(t_list **list, t_list **add)
{
	if (!list || !add)
		return ;
	if (*list)
	{
		if (*add)
		{
			(*list)->end->next = *add;
			(*list)->end = (*add)->end;
		}
	}
	else if (*add)
		*list = *add;
}
