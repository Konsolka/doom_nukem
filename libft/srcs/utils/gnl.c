/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:40:33 by user              #+#    #+#             */
/*   Updated: 2020/11/04 16:00:56 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "private_gnl.h"

int			check_buf(char **buf, t_gnl_list **storage, char **line)
{
	char		*npos;
	char		*new_str;
	size_t		buflen;

	if (!*buf)
		return (__GNL_NOT_FOUNDED);
	buflen = ft_strlen(*buf);
	npos = ft_memchr(*buf, '\n', buflen);
	if (npos)
	{
		*npos = '\0';
		*line = ft_strdup(*buf);
		new_str = (npos[1] != '\0') ? ft_strdup(npos + 1) : NULL;
		free(*buf);
		*buf = new_str;
		return (__GNL_FOUNDED);
	}
	else
	{
		gnl_add_node(storage, gnl_create_list_from_src(*buf, buflen));
		*buf = NULL;
		return (__GNL_NOT_FOUNDED);
	}
}

char		*list_to_str(t_gnl_list *list)
{
	char	*str;
	size_t	offset;

	if (list)
	{
		str = malloc(list->total_len + 1);
		offset = 0;
		while (list)
		{
			ft_memcpy(str + offset, list->str, list->strlen);
			offset += list->strlen;
			list = list->next;
		}
		str[offset] = '\0';
	}
	else
		str = ft_strdup("");
	return (str);
}

void		list_delete(t_gnl_list *list)
{
	t_gnl_list	*temp;

	while (list)
	{
		temp = list->next;
		if (list->is_from_sources)
			free(list->str);
		free(list);
		list = temp;
	}
}

int			gnl(const int fd, char **line)
{
	static char		*buf;
	char			data[GNL_BUF + 1];
	t_gnl_list		*store;
	ssize_t			ret;
	char			*npos;

	store = NULL;
	npos = NULL;
	if (check_buf(&buf, &store, line) == __GNL_FOUNDED)
		return (GNL_OK);
	while ((ret = read(fd, data, GNL_BUF)) > 0)
	{
		data[ret] = '\0';
		npos = ft_memchr(data, '\n', ret);
		if (npos != data)
			gnl_add_node(&store, gnl_new_list(data, npos ? npos - data : ret));
		if (npos)
			break ;
	}
	if (!ret && !store)
		return (GNL_EOF);
	*line = list_to_str(store);
	list_delete(store);
	buf = (npos && npos[1] != '\0') ? ft_strdup(npos + 1) : NULL;
	return (GNL_OK);
}
