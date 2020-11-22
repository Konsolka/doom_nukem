/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:29:28 by user              #+#    #+#             */
/*   Updated: 2020/11/22 14:20:13 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H

# include "ft_types.h"
# include "ft_memory.h"

bool		ft_strcmp(const char *str1, const char *str2);
char		*ft_strchr(const char *str, int character);
char		*ft_strdup(const char *str);
char		*ft_strndup(const char *src, size_t bytes);
bool		ft_strequ(const char *s1, const char *s2);
bool		ft_strnequ(const char *s1, const char *s2, size_t symbols);
size_t		ft_strlen(const char *str);

bool		ft_isspace(int c);
bool		ft_isdigit(int c);
bool		ft_isalpha(int c);
char		*ft_strjoin(char const *s1, char const *s2);

#endif
