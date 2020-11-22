/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_pushback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:43 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/17 15:05:05 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "private_vector.h"

static t_vector_s		*vec_expand(t_vector_s *vector)
{
	t_vector_s		*new_vector;
	size_t			new_datasize;

	if (vector->size < 64)
		new_datasize = vector->size + 16;
	else
		new_datasize = vector->size * VEC_INCREASE;
	new_vector = vec_create(new_datasize, vector->typesize) -
															sizeof(t_vector_s);
	new_vector->size = vector->size;
	new_vector->capacity = new_datasize - vector->size;
	ft_memcpy(new_vector->data, vector->data, vector->size * vector->typesize);
	free(vector);
	return (new_vector);
}

#ifdef SAFE_MODE

void					vec_pushback(t_vector vector, void *elem)
{
	t_vector_s		*vec;

	if (!vector)
		ft_error("invalid param \"vecptr\": cannot be NULL)",
				"vec_pushback", 0);
	if (!elem)
		ft_error("invalid param \"elem\": cannot be NULL)",
				"vec_pushback", 0);
	vec = *(void**)vector - sizeof(t_vector_s);
	if (!vec->capacity)
	{
		vec = vec_expand(vec);
		*(void**)vector = vec->data;
	}
	ft_memcpy(vec->data + vec->size * vec->typesize,
				elem, vec->typesize);
	++vec->size;
	--vec->capacity;
}

#else

void					vec_pushback(t_vector vector, void *elem)
{
	t_vector_s		*vec;

	vec = *(void**)vector - sizeof(t_vector_s);
	if (!vec->capacity)
	{
		vec = vec_expand(vec);
		*(void**)vector = vec->data;
	}
	ft_memcpy(vec->data + vec->size * vec->typesize,
				elem, vec->typesize);
	++vec->size;
	--vec->capacity;
}

#endif
