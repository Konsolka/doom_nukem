/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:14:15 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:14:16 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex		complex_add(const t_complex *c1, const t_complex *c2)
{
	t_complex	res;

	res.re = c1->re + c2->re;
	res.im = c1->im + c2->im;
	return (res);
}
