/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_bits_array.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:06:40 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 17:20:51 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRIVATE_BITS_ARRAY_H
# define PRIVATE_BITS_ARRAY_H

# include "ft_bits_arr.h"

typedef struct			s_barr
{
	size_t				size_in_int_ws;
	size_t				size_in_bits;
	t_int_ws			*data;
}						t_barr;

void					convert_to_string(char *str, t_int_ws *data,
											size_t datalen);

#endif
