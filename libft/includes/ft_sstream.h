/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sstream.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/18 11:42:52 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:33:33 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSTREAM_H
# define FT_SSTREAM_H

# include <stdlib.h>
# include "ft_types.h"

# define SSTREAM_EMPTY	(-1)

typedef struct		s_stringstream
{
	size_t			strlen;
	size_t			pos;
	char			*str;
	char			separator;
	bool			is_empty;
}					t_stringstream;

t_stringstream		*sstream_create(const char *str);

void				sstream_add(t_stringstream *ss, const char *str);
char				*sstream_get_str(t_stringstream *ss);
char				*sstream_getline(t_stringstream *ss, char delimiter);
char				sstream_peek(t_stringstream *ss);
char				sstream_get(t_stringstream *ss);
void				sstream_skip(t_stringstream *ss, size_t symbols);
size_t				sstream_getn(t_stringstream *ss, char *buf, size_t chars);
void				sstream_set_separator(t_stringstream *ss, char separator);
void				sstream_clear(t_stringstream *ss);
const char			*sstream_str(t_stringstream *ss);
bool				sstream_empty(t_stringstream *ss);

void				sstream_destroy(t_stringstream *ss);

#endif
