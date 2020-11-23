/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ssectors.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mburl <mburl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 16:31:19 by mburl             #+#    #+#             */
/*   Updated: 2020/11/23 16:43:58 by mburl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SSECTORS_H
# define SSECTORS_H

#include <stdint.h>

typedef struct	s_ssectors
{
	int16_t		seg_count;
	int16_t		first_seg_num;
}				t_ssectors;
#endif