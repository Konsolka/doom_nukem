/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_empty.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:44:12 by user              #+#    #+#             */
/*   Updated: 2020/04/24 16:33:36 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"

bool	sstream_empty(t_stringstream *ss)
{
	return (ss->is_empty);
}
