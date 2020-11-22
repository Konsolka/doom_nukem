/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_sub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:14:11 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:14:13 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex			complex_sub(const t_complex *c1, const t_complex *c2)
{
	t_complex		res;

	res.re = c1->re - c2->re;
	res.im = c1->im - c2->im;
	return (res);
}
