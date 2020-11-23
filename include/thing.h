/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thing.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 12:52:51 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 15:39:31 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THING_H
# define THING_H

# include <stdint.h>

typedef struct	s_thing
{
	int16_t	x_pos;
	int16_t	y_pos;
	int16_t	angle;
	int16_t	type;
	int16_t	flag;
}				t_thing;

#endif