/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:55 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/22 02:35:30 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

/**
 * Get heuristic cost to reach dest from pos
 * Using Pytagorath theorem (Manhattan)
 * dest : destination
 * pos : current position
*/
// static float	get_heuristic_cost(t_pos dest, t_pos pos)
// {
// 	return (sqrt(abs((int)(dest.x - pos.x)) + abs((int)(dest.y - pos.y))));
// }

bool	verify_path_map(t_list *map, t_pos *pos_a, t_pos *pos_b)
{
	(void)map;
	(void)pos_a;
	(void)pos_b;
	return (true);
}
