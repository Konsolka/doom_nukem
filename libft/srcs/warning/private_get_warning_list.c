/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   private_get_warning_list.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:45:07 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:45:08 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private_warning.h"

t_warning_list	**get_warning_list(void)
{
	static		t_warning_list	*warning_list;

	return (&warning_list);
}
