/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:14:17 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:14:18 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex		complex_init(long double re, long double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}
