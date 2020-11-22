/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 12:08:48 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:33:14 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALGORITHM_H
# define FT_ALGORITHM_H

# include "ft_types.h"

bool		all_of(void *range_begin, size_t elems, size_t elem_size,
					bool (*estimate)(void *elem));

#endif
