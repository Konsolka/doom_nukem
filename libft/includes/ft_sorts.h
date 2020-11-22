/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorts.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:29:29 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:31:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SORTS_H
# define FT_SORTS_H

# include "ft_types.h"
# include "ft_utils.h"

void			ft_bubble_sort(void *arr, size_t elems, size_t elem_size,
								int (*cmp) (const void *, const void *));

#endif
