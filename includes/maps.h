/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:14:53 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/22 02:37:04 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "so_long.h"

t_list	*read_map(char *filename);
bool	verify_wall_map(t_list *map);
bool	verify_elements_in_map(t_list *map);
bool	verify_path_map(t_list *map, t_pos *pos_a, t_pos *pos_b);
t_pos	*get_object_pos_map(t_list *map, char element);
t_list	*get_object_pos_list_map(t_list *map, char element);

typedef struct s_elements_map {
	bool	item;
	bool	exit;
	bool	person;
}	t_elements_map;

#endif