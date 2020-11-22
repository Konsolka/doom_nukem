/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf_add_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 02:19:34 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/18 11:44:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"
#include "private_buf.h"

#ifdef SAFE_MODE

void			buf_add_line(int fd, char *str)
{
	if (!str)
		ft_error("invalid param \"str\": cannot be NULL", "buf_add_line", 0);
	buf_add_str(fd, str);
	buf_add_chr(fd, '\n', 1);
}

#else

void			buf_add_line(int fd, char *str)
{
	buf_add_str(fd, str);
	buf_add_chr(fd, '\n', 1);
}

#endif
