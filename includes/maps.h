/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:14:53 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 16:35:30 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "so_long.h"

t_list	*read_map(char *filename);
BOOL	verify_wall_map(t_list *map);
BOOL	verify_elements_in_map(t_list *map);
BOOL	verify_path_map(t_list *map);

typedef struct s_elements_map {
	BOOL	item;
	BOOL	exit;
	BOOL	person;
}	t_elements_map;

#endif