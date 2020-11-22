/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_getn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 20:16:14 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:34:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"
#include "ft_utils.h"

size_t			sstream_getn(t_stringstream *ss, char *buf, size_t chars)
{
	size_t		written;

	if (ss->is_empty)
		written = 0;
	else
	{
		written = chars < ss->strlen - ss->pos ? chars : ss->strlen - ss->pos;
		ft_memcpy(buf, ss->str + ss->pos, written);
		ss->pos += written;
		if (ss->pos == ss->strlen)
		{
			free(ss->str);
			ss->str = NULL;
			ss->is_empty = true;
		}
	}
	return (written);
}
