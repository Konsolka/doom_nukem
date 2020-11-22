/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:31:44 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/28 10:08:46 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "private_vector.h"

#ifdef SAFE_MODE

void			vec_destroy(t_vector vector)
{
	if (!vector)
		ft_error("invalid param \"vecptr\": cannot be NULL)",
				"vec_destroy", 0);
	free(*(void**)vector - sizeof(t_vector_s));
}

#else

inline void		vec_destroy(t_vector vector)
{
	free(*(void**)vector - sizeof(t_vector_s));
}

#endif
