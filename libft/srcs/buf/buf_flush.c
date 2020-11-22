/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_flush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:29:21 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/12 14:09:47 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"
#include "private_buf.h"

#ifdef SAFE_MODE

void			buf_flush(int fd)
{
	t_buf		*buf;

	buf = *get_buf(fd);
	if (!buf)
		ft_error("buf was not allocated", "buf_flush", 0);
	if (buf->pos)
	{
		write(buf->fd, buf->buf, buf->pos);
		buf->printed += buf->pos;
		buf->pos = 0;
	}
}

#else

void			buf_flush(int fd)
{
	t_buf		*buf;

	buf = *get_buf(fd);
	if (buf->pos)
	{
		write(buf->fd, buf->buf, buf->pos);
		buf->printed += buf->pos;
		buf->pos = 0;
	}
}

#endif
