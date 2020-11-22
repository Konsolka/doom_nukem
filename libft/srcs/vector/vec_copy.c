/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_copy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:44 by dbendu            #+#    #+#             */
/*   Updated: 2020/04/24 16:05:52 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "private_vector.h"

#ifdef SAFE_MODE

void			*vec_copy(t_vector vector, bool save_capacity)
{
	t_vector_s	*vec;
	t_vector_s	*new_vector;
	size_t		new_size;

	if (!vector)
		ft_error("invalid param \"vecptr\": cannot be NULL)",
				"vec_copy", 0);
	vec = *(void**)vector - sizeof(t_vector_s);
	new_size = vec->size;
	if (save_capacity)
		new_size += vec->capacity;
	new_vector = vec_create(new_size, vec->typesize) - sizeof(t_vector_s);
	new_vector->size = vec->size;
	new_vector->capacity = new_size - vec->size;
	new_vector->data = (void*)new_vector + sizeof(t_vector_s);
	ft_memcpy(new_vector->data, vec->data, vec->size * vec->typesize);
	return (new_vector->data);
}

#else

void			*vec_copy(t_vector vector, bool save_capacity)
{
	t_vector_s	*vec;
	t_vector_s	*new_vector;
	size_t		new_size;

	vec = *(void**)vector - sizeof(t_vector_s);
	new_size = vec->size;
	if (save_capacity)
		new_size += vec->capacity;
	new_vector = vec_create(new_size, vec->typesize) - sizeof(t_vector_s);
	new_vector->size = vec->size;
	new_vector->capacity = new_size - vec->size;
	new_vector->data = (void*)new_vector + sizeof(t_vector_s);
	ft_memcpy(new_vector->data, vec->data, vec->size * vec->typesize);
	return (new_vector->data);
}

#endif
