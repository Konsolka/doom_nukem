/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:44:36 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:44:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_warning.h"
#include "private_warning.h"

void		warning_destroy(void)
{
	t_warning_list	**warning_list_ptr;
	t_warning_list	*warning_list;
	t_warning		*temp;

	warning_list_ptr = get_warning_list();
	warning_list = *warning_list_ptr;
	while (warning_list->errors)
	{
		temp = warning_list->errors->next;
		free(warning_list->errors->message);
		free(warning_list->errors);
		warning_list->errors = temp;
	}
	while (warning_list->warnings)
	{
		temp = warning_list->warnings->next;
		free(warning_list->warnings->message);
		free(warning_list->warnings);
		warning_list->warnings = temp;
	}
	free(warning_list);
	*warning_list_ptr = NULL;
}
