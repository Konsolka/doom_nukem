/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:40:36 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:34:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"

char	sstream_get(t_stringstream *ss)
{
	char	ret;

	if (ss->is_empty)
		return (-1);
	else
	{
		ret = ss->str[ss->pos];
		ss->pos += 1;
		if (ss->pos == ss->strlen)
		{
			free(ss->str);
			ss->str = NULL;
			ss->is_empty = true;
		}
		return (ret);
	}
}
