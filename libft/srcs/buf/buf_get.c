/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_get.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:29:21 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/12 14:09:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"
#include "private_buf.h"

#ifdef SAFE_MODE

char		*buf_get(int fd, size_t *symbols_in_buf)
{
	t_buf	**buf;

	buf = get_buf(fd);
	if (!*buf)
		ft_error("buf was not allocated", "buf_get", 0);
	if (symbols_in_buf)
		*symbols_in_buf = (*buf)->pos;
	return ((*buf)->buf);
}

#else

char		*buf_get(int fd, size_t *symbols_in_buf)
{
	t_buf	**buf;

	buf = get_buf(fd);
	if (symbols_in_buf)
		*symbols_in_buf = (*buf)->pos;
	return ((*buf)->buf);
}

#endif
