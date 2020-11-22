/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:29:22 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/12 14:10:37 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_buf.h"
#include "private_buf.h"

#ifdef SAFE_MODE

size_t			buf_destroy(int fd)
{
	t_buf		**buf;
	size_t		printed_symbols;

	buf = get_buf(fd);
	if (!*buf)
		ft_error("buf was not allocated", "buf_destroy", 0);
	printed_symbols = (*buf)->printed;
	free(*buf);
	*buf = NULL;
	return (printed_symbols);
}

#else

size_t			buf_destroy(int fd)
{
	t_buf		**buf;
	size_t		printed_symbols;

	buf = get_buf(fd);
	printed_symbols = (*buf)->printed;
	free(*buf);
	*buf = NULL;
	return (printed_symbols);
}

#endif
