/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_pow3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbendu <dbendu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:09:57 by dbendu            #+#    #+#             */
/*   Updated: 2020/03/06 19:14:32 by dbendu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex			complex_pow3(const t_complex *c)
{
	t_complex		pow2;

	pow2 = complex_pow2(c);
	return (complex_mult(c, &pow2));
}
