/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:29:23 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/12 14:12:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_buf.h"
#include "private_buf.h"

#ifdef SAFE_MODE

void			buf_create(int fd, size_t bufsize)
{
	t_buf		**buf;

	if (fd < 0)
		ft_error("invalid param \"fd\": cannot be less than 0",
				"buf_create", 0);
	else if (fd > MAX_BUF_FD)
		ft_error("fd more than max allowed fd. Change macros in \
\"private_buf.h\" file", "buf_create", 0);
	buf = get_buf(fd);
	if (*buf)
		ft_error("buf already allocated",
				"buf_create", 0);
	if (!bufsize)
		bufsize = DEFAULT_BUFSIZE;
	*buf = malloc(sizeof(t_buf) + bufsize);
	if (!buf)
		ft_error("can\'t allocate buffer", "buf_init", 0);
	(*buf)->size = bufsize;
	(*buf)->pos = 0;
	(*buf)->fd = fd;
	(*buf)->printed = 0;
	(*buf)->buf = (void*)*buf + sizeof(t_buf);
}

#else

void			buf_create(int fd, size_t bufsize)
{
	t_buf		**buf;

	buf = get_buf(fd);
	if (!bufsize)
		bufsize = DEFAULT_BUFSIZE;
	*buf = malloc(sizeof(t_buf) + bufsize);
	if (!buf)
		ft_error("can\'t allocate buffer", "buf_init", 0);
	(*buf)->size = bufsize;
	(*buf)->pos = 0;
	(*buf)->fd = fd;
	(*buf)->printed = 0;
	(*buf)->buf = (void*)*buf + sizeof(t_buf);
}

#endif
