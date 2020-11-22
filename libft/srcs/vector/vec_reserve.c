/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reserve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:43 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/26 21:50:28 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "private_vector.h"

#ifdef SAFE_MODE

void			vec_reserve(t_vector vector, int elems)
{
	t_vector_s	*vec;
	int			total_cells;

	if (!vector)
		ft_error("invalid param \"vecptr\": cannot be NULL)",
				"vec_reserve", 0);
	vec = *(void**)vector - sizeof(t_vector_s);
	total_cells = vec->capacity + vec->size;
	if (elems > total_cells)
		ft_error("invalid param \"vecptr\": don\'t have enought memory",
				"vec_reserve", 0);
	vec->size = elems;
	vec->capacity = total_cells - elems;
}

#else

void			vec_reserve(t_vector vector, int elems)
{
	t_vector_s	*vec;
	int			total_cells;

	vec = *(void**)vector - sizeof(t_vector_s);
	total_cells = vec->capacity + vec->size;
	vec->size = elems;
	vec->capacity = total_cells - elems;
}

#endif
