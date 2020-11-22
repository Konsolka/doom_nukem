/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 14:20:11 by user              #+#    #+#             */
/*   Updated: 2020/04/04 14:26:26 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*ft_strndup(const char *src, size_t bytes)
{
	const size_t	srclen = ft_strlen(src);
	char			*str;

	if (bytes > srclen)
		bytes = srclen;
	str = malloc(bytes + 1);
	ft_memcpy(str, src, bytes);
	str[bytes] = '\0';
	return (str);
}
