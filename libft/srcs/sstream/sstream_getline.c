/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_getline.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 22:05:19 by user              #+#    #+#             */
/*   Updated: 2020/04/18 11:36:03 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"
#include "ft_memory.h"

char	*sstream_getline(t_stringstream *ss, char delimiter)
{
	char	separator;
	char	*str;

	separator = ss->separator;
	ss->separator = delimiter;
	str = sstream_get_str(ss);
	ss->separator = separator;
	return (str);
}
