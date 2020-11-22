/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_buf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:29:19 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/12 14:08:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_BUF_H
# define PRIVATE_BUF_H

# include "ft_buf.h"

# define MAX_BUF_FD			10

typedef struct			s_buf
{
	size_t				size;
	size_t				pos;
	size_t				printed;
	int					fd;
	char				*buf;
}						t_buf;

t_buf					**get_buf(int fd);

#endif
