/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_add_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:29:23 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/12 14:12:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"
#include "private_buf.h"

#ifdef SAFE_MODE

static void		check_args(t_buf *buf, const char *str)
{
	if (!buf)
		ft_error("buf was not allocated", "buf_add_str", 0);
	if (!str)
		ft_error("invalid param \"str\": cannot be NULL", "buf_add_str", 0);
}

void			buf_add_str(int fd, const char *str)
{
	t_buf		*buf;
	size_t		strlen;

	buf = *get_buf(fd);
	check_args(buf, str);
	strlen = ft_strlen(str);
	if (strlen < buf->size - buf->pos)
	{
		ft_memcpy(buf->buf + buf->pos, str, strlen);
		buf->pos += strlen;
	}
	else
	{
		buf_flush(fd);
		if (strlen > buf->size * 0.75)
		{
			write(buf->fd, str, strlen);
			buf->printed += strlen;
		}
		else
		{
			ft_memcpy(buf->buf, str, strlen);
			buf->pos += strlen;
		}
	}
}

#else

void			buf_add_str(int fd, const char *str)
{
	t_buf		*buf;
	size_t		strlen;

	buf = *get_buf(fd);
	strlen = ft_strlen(str);
	if (strlen < buf->size - buf->pos)
	{
		ft_memcpy(buf->buf + buf->pos, str, strlen);
		buf->pos += strlen;
	}
	else
	{
		buf_flush(fd);
		if (strlen > buf->size * 0.75)
		{
			write(buf->fd, str, strlen);
			buf->printed += strlen;
		}
		else
		{
			ft_memcpy(buf->buf, str, strlen);
			buf->pos += strlen;
		}
	}
}

#endif
