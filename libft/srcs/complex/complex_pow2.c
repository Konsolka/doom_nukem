/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_pow2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:14:21 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:14:21 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex		complex_pow2(const t_complex *c)
{
	t_complex	res;

	res.re = c->re * c->re - c->im * c->im;
	res.im = 2 * c->re * c->im;
	return (res);
}
