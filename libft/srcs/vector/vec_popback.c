/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_popback.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 11:59:29 by user              #+#    #+#             */
/*   Updated: 2020/04/17 20:14:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "private_vector.h"

inline void	vec_popback(t_vector vector)
{
	if (((t_vector_s*)(*(void**)vector - sizeof(t_vector_s)))->size)
		((t_vector_s*)(*(void**)vector - sizeof(t_vector_s)))->size -= 1;
}
