/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_peek.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:38:38 by user              #+#    #+#             */
/*   Updated: 2020/04/17 19:42:59 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"

char	sstream_peek(t_stringstream *ss)
{
	if (ss->is_empty)
		return (-1);
	else
		return (ss->str[ss->pos]);
}
