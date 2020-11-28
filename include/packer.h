/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: konsolka <konsolka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/28 20:03:56 by konsolka          #+#    #+#             */
/*   Updated: 2020/11/28 20:06:41 by konsolka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PACKER_H
# define PACKER_H

# include <stdint.h>

typedef struct s_readed_file
{
	uint8_t		*content;
	uint64_t	size;
}				t_readed_file;


#endif