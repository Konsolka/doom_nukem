/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:29:05 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:34:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"
#include "ft_string.h"

static inline char	*copy_str(const char *str, size_t strlen)
{
	char *new_str;

	new_str = malloc(strlen + 1);
	return (ft_memcpy(new_str, str, strlen + 1));
}

t_stringstream		*sstream_create(const char *str)
{
	t_stringstream	*ss;

	ss = malloc(sizeof(t_stringstream));
	ss->separator = ' ';
	if (str && str[0] != '\0')
	{
		ss->is_empty = false;
		ss->strlen = ft_strlen(str);
		ss->str = copy_str(str, ss->strlen);
		ss->pos = 0;
	}
	else
	{
		ss->is_empty = true;
		ss->str = NULL;
	}
	return (ss);
}
