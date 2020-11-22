/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:38:58 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:38:58 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	*ft_strchr(const char *str, int character)
{
	while (*str)
	{
		if (*str == character)
			return ((char*)str);
		++str;
	}
	if (character == '\0')
		return ((char*)str);
	return (NULL);
}
