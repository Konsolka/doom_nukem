/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sstream_set_separator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/17 19:36:42 by user              #+#    #+#             */
/*   Updated: 2020/04/17 20:05:19 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sstream.h"

void	sstream_set_separator(t_stringstream *ss, char separator)
{
	ss->separator = separator;
}
