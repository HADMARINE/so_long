/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_map_ext.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:48:13 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/24 14:49:40 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Get heuristic cost to reach dest from pos
 * Using Pytagorath theorem (Manhattan)
 * dest : destination
 * pos : current position
 */
double	get_heuristic_cost(t_pos *dest, t_pos *pos)
{
	return (sqrt(abs(dest->x - pos->x) + abs(dest->y - pos->y)));
}

/**
 * val : t_path_node
 * dat : t_pos
*/
bool	lstchr_vpm(void *val, void *dat)
{
	if (((t_path_node *)val)->pos->x == ((t_pos *)dat)->x
		&& ((t_path_node *)val)->pos->y == ((t_pos *)dat)->y)
		return (true);
	return (false);
}

bool	eval_path_node(void *node1, void *node2)
{
	if (((t_path_node *)node1)->went == false
		&& ((t_path_node *)node2)->went == true)
		return (false);
	if (((t_path_node *)node1)->went == true
		&& ((t_path_node *)node2)->went == false)
		return (true);
	if (((double)((t_path_node *)node1)->dist_e
		+ ((t_path_node *)node1)->dist_s)
		> ((double)((t_path_node *)node2)->dist_e
			+ ((t_path_node *)node2)->dist_s))
		return (true);
	if (((double)((t_path_node *)node1)->dist_e
		+ ((t_path_node *)node1)->dist_s)
		== ((double)((t_path_node *)node2)->dist_e
			+ ((t_path_node *)node2)->dist_s))
	{
		if (((t_path_node *)node1)->dist_e > ((t_path_node *)node2)->dist_e)
			return (true);
		return (false);
	}
	return (false);
}

t_pos	get_offset_by_dir(t_direction dir)
{
	t_pos	offset;

	if (dir == LEFT)
		offset = get_init_pos_value(-1, 0);
	else if (dir == RIGHT)
		offset = get_init_pos_value(1, 0);
	else if (dir == UP)
		offset = get_init_pos_value(0, -1);
	else
		offset = get_init_pos_value(0, 1);
	return (offset);
}

void	*free_and_go_vpm(t_pos *pos)
{
	free(pos);
	return (NULL);
}
