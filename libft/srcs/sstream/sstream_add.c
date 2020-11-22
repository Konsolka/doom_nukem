/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:32:25 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:34:35 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"
#include "ft_string.h"

static char			*build_new_str(const char *old_str, size_t old_str_len,
									const char *new_str_ptr,
									size_t *new_len_ptr)
{
	char	*new_str;
	size_t	new_str_len;
	size_t	new_total_len;

	new_str_len = ft_strlen(new_str_ptr);
	new_total_len = new_str_len + old_str_len;
	new_str = malloc(new_total_len + 1);
	ft_memcpy(new_str, old_str, old_str_len);
	ft_memcpy(new_str + old_str_len, new_str_ptr, new_str_len + 1);
	*new_len_ptr = new_total_len;
	return (new_str);
}

void				sstream_add(t_stringstream *ss, const char *str)
{
	char	*new_str;

	if (ss->is_empty)
	{
		ss->strlen = ft_strlen(str);
		ss->str = malloc(ss->strlen + 1);
		ft_memcpy(ss->str, str, ss->strlen + 1);
		ss->is_empty = false;
		ss->pos = 0;
	}
	else
	{
		new_str = build_new_str(ss->str + ss->pos, ss->strlen - ss->pos,
								str, &ss->strlen);
		free(ss->str);
		ss->str = new_str;
		ss->pos = 0;
	}
}
