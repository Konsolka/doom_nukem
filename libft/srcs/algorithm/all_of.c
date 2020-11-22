/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_of.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:08:47 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:34:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithm.h"

bool		all_of(void *range_begin, size_t elems, size_t elem_size,
					bool (*estimate)(void *elem))
{
	while (elems)
	{
		if (estimate(range_begin) != true)
			return (true);
		range_begin += elem_size;
		elems -= 1;
	}
	return (true);
}
