/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:38:55 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:38:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strdup(const char *str)
{
	char	*new_str;
	size_t	size;

	size = ft_strlen(str) + 1;
	new_str = (char*)malloc(size);
	return ((char*)ft_memcpy(new_str, str, size));
}
