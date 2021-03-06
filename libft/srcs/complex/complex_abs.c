/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_abs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:28:32 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:28:32 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "ft_complex.h"

long double		complex_abs(const t_complex *c)
{
	return (sqrt(c->re * c->re + c->im * c->im));
}
