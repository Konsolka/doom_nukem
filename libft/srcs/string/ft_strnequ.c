/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:38:51 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:34:44 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

bool		ft_strnequ(const char *s1, const char *s2, size_t symbols)
{
	while (*s1 && symbols)
	{
		if (*s1 != *s2)
			return (false);
		--symbols;
		++s1;
		++s2;
	}
	return (true);
}
