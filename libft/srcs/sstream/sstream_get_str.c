/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_get_str.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 21:25:33 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:34:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"
#include "ft_memory.h"

static void			free_ss(t_stringstream *ss)
{
	free(ss->str);
	ss->str = NULL;
	ss->is_empty = true;
}

static char			*find_begin(char *str, char separator)
{
	char	*begin;

	begin = str;
	while (*begin == separator)
		begin += 1;
	return (begin);
}

static char			*find_end(char *begin, char separator)
{
	char	*end;

	end = begin;
	while (*end && *end != separator)
		end += 1;
	return (end);
}

static char			*create_str(char *begin, char *end)
{
	char	*str;

	str = malloc(end - begin + 1);
	ft_memcpy(str, begin, end - begin);
	str[end - begin] = '\0';
	return (str);
}

char				*sstream_get_str(t_stringstream *ss)
{
	char	*begin;
	char	*end;
	char	*str;

	if (ss->is_empty)
		return (NULL);
	begin = find_begin(ss->str + ss->pos, ss->separator);
	if (*begin == '\0')
	{
		free_ss(ss);
		return (NULL);
	}
	end = find_end(begin, ss->separator);
	ss->pos = end - ss->str;
	str = create_str(begin, end);
	if (end[0] == '\0' || end[1] == '\0')
		free_ss(ss);
	return (str);
}
