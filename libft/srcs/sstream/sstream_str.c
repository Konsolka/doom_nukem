/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:37:25 by user              #+#    #+#             */
/*   Updated: 2020/04/18 11:46:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"
#include "ft_memory.h"

const char			*sstream_str(t_stringstream *ss)
{
	if (ss->is_empty)
		return (NULL);
	else
		return (ss->str + ss->pos);
}
