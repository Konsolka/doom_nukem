/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   warning_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 12:44:18 by user              #+#    #+#             */
/*   Updated: 2020/04/03 12:44:18 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_warning.h"
#include "private_warning.h"

inline void	warning_create(void)
{
	t_warning_list	**warning_list;

	warning_list = get_warning_list();
	*warning_list = ft_calloc(1, sizeof(t_warning_list));
}
