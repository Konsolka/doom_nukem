/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_gnl_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:41:05 by user              #+#    #+#             */
/*   Updated: 2020/11/04 15:59:02 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "private_gnl.h"
#include "ft_memory.h"

t_gnl_list			*gnl_new_list(char *str, size_t strlen)
{
	t_gnl_list		*new_list;

	new_list = malloc(sizeof(t_gnl_list) + strlen + 1);
	new_list->strlen = strlen;
	new_list->str = (void*)new_list + sizeof(t_gnl_list);
	ft_memcpy(new_list->str, str, strlen);
	new_list->str[strlen] = '\0';
	new_list->next = NULL;
	new_list->end = NULL;
	new_list->is_from_sources = false;
	return (new_list);
}

t_gnl_list			*gnl_create_list_from_src(char *str, size_t strlen)
{
	t_gnl_list		*new_list;

	new_list = malloc(sizeof(t_gnl_list));
	new_list->str = str;
	new_list->strlen = strlen;
	new_list->next = NULL;
	new_list->end = NULL;
	new_list->is_from_sources = true;
	return (new_list);
}

void				gnl_add_node(t_gnl_list **list, t_gnl_list *node)
{
	if (*list)
	{
		(*list)->end->next = node;
		(*list)->end = node;
		(*list)->total_len += node->strlen;
	}
	else
	{
		node->end = node;
		*list = node;
		(*list)->total_len = node->strlen;
	}
}
