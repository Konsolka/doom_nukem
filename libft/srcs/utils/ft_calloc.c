/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 23:57:10 by user              #+#    #+#             */
/*   Updated: 2020/03/01 23:57:20 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "mode_libft.h"

#ifdef XMALLOC_MODE

void		*ft_calloc(size_t elems, size_t elem_size)
{
	void	*ptr;
	size_t	size;

	size = elems * elem_size;
	ptr = malloc(size);
	if (!ptr)
		ft_error("can\'t allocate memory", "ft_calloc", 2);
	ft_memset(ptr, 0, size);
	return (ptr);
}

#else

void		*ft_calloc(size_t elems, size_t elem_size)
{
	void	*ptr;
	size_t	size;

	size = elems * elem_size;
	ptr = malloc(size);
	if (ptr)
		ft_memset(ptr, 0, size);
	return (ptr);
}

#endif
