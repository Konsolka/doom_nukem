/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:39:44 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:39:45 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"

void		ft_error(const char *msg, const char *func, int code)
{
	if (func)
	{
		write(2, "\e[38;5;196mError\e[0m in function ", 33);
		write(2, func, ft_strlen(func));
	}
	if (msg)
	{
		if (!func)
			write(2, "\e[38;5;196mError\e[0m", 20);
		write(2, ": ", 2);
		write(2, msg, ft_strlen(msg));
	}
	if (func || msg)
		write(2, "\n", 1);
	exit(code);
}
