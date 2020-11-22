/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:29:35 by user              #+#    #+#             */
/*   Updated: 2020/04/15 20:36:16 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BUF_H
# define FT_BUF_H

# define DEFAULT_BUFSIZE	4096

# include <unistd.h>
# include "ft_types.h"
# include "ft_utils.h"
# include "ft_memory.h"
# include "ft_string.h"
# include "mode_libft.h"

void					buf_create(int fd, size_t bufsize);
size_t					buf_destroy(int fd);

char					*buf_get(int fd, size_t *symbols_in_buf);
void					buf_flush(int fd);
size_t					buf_printed_count(int fd);

void					buf_add_chr(int fd, char chr, size_t times);
void					buf_add_str(int fd, const char *str);
void					buf_add_strn(int fd, const char *str, size_t strlen);
void					buf_add_line(int fd, char *str);

#endif
