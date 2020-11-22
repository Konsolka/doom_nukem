/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:44:09 by user              #+#    #+#             */
/*   Updated: 2020/04/12 14:13:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_warning.h"
#include "private_warning.h"

void			warning_print(void)
{
	const t_warning_list	*warning_list = *get_warning_list();
	t_warning				*iter;

	buf_create(2, 1024);
	iter = warning_list->warnings;
	while (iter)
	{
		buf_add_strn(2, "\e[38;5;99mWarning\e[0m: ", 23);
		buf_add_line(2, iter->message);
		iter = iter->next;
	}
	if (warning_list->errors_end && warning_list->warnings)
		buf_add_chr(2, '\n', 1);
	iter = warning_list->errors;
	while (iter)
	{
		buf_add_strn(2, "\e[38;5;001mError\e[0m: ", 22);
		buf_add_line(2, iter->message);
		iter = iter->next;
	}
	buf_flush(2);
	buf_destroy(2);
}
