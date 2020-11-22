/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:47:50 by user              #+#    #+#             */
/*   Updated: 2020/04/04 12:13:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_warning.h"
#include "private_warning.h"

static t_vector_char	*get_parts_list(va_list argptr,
										int parts_amount,
										t_vector_sizet *lenghts,
										size_t *total_len)
{
	t_vector_char		*parts;
	t_vector_sizet		parts_lenghts;
	char				*part;
	size_t				part_lenght;

	*total_len = 0;
	parts = vec_create(parts_amount, sizeof(t_vector_char));
	parts_lenghts = vec_create(parts_amount, sizeof(size_t));
	while (parts_amount--)
	{
		part = va_arg(argptr, char*);
		part_lenght = ft_strlen(part);
		*total_len += part_lenght;
		vec_pushback(&parts, &part);
		vec_pushback(&parts_lenghts, &part_lenght);
	}
	*lenghts = parts_lenghts;
	return (parts);
}

static char				*build_error_message(int message_parts,
											t_vector_char *msg_parts,
											t_vector_sizet parts_lenghts,
											size_t total_lenght)
{
	char			*message;
	size_t			offset;
	int				cur_part;

	offset = 0;
	message = malloc(total_lenght + 1);
	cur_part = 0;
	while (cur_part < message_parts)
	{
		ft_memcpy(message + offset, msg_parts[cur_part],
				parts_lenghts[cur_part]);
		offset += parts_lenghts[cur_part];
		cur_part += 1;
	}
	message[total_lenght] = '\0';
	return (message);
}

static void				warning_list_add(t_warning *new_warning,
										t_warning_type type)
{
	t_warning_list		*warning_list;

	warning_list = *get_warning_list();
	if (type == ERROR)
	{
		if (!warning_list->errors)
			warning_list->errors = new_warning;
		else
			warning_list->errors_end->next = new_warning;
		warning_list->errors_end = new_warning;
	}
	else
	{
		if (!warning_list->warnings)
			warning_list->warnings = new_warning;
		else
			warning_list->warnings_end->next = new_warning;
		warning_list->warnings_end = new_warning;
	}
}

static t_warning		*create_warning(char *message)
{
	t_warning	*warning;

	warning = malloc(sizeof(t_warning));
	warning->message = message;
	warning->next = NULL;
	return (warning);
}

void					warning_add(t_warning_type type,
									int message_parts, ...)
{
	t_vector_char	*parts;
	t_vector_sizet	parts_lenghts;
	size_t			total_lenght;
	va_list			argptr;
	char			*full_message;

	va_start(argptr, message_parts);
	parts = get_parts_list(argptr, message_parts,
							&parts_lenghts, &total_lenght);
	va_end(argptr);
	full_message = build_error_message(message_parts, parts,
										parts_lenghts, total_lenght);
	warning_list_add(create_warning(full_message), type);
	vec_destroy(&parts);
	vec_destroy(&parts_lenghts);
}
