/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:55 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/22 15:54:27 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

/**
 * Get heuristic cost to reach dest from pos
 * Using Pytagorath theorem (Manhattan)
 * dest : destination
 * pos : current position
 */
static float	get_heuristic_cost(t_pos *dest, t_pos *pos)
{
	return (sqrt(abs((int)(dest->x - pos->x)) + abs((int)(dest->y - pos->y))));
}

static bool	lstchr_vpm(void *val)
{
	return true;
}

static int	eval_path_node(t_path_node *node)
{
	int	val;

	val = 0;
	val += node->dist_e + node->dist_s;
	return (val);
}

static t_pos	get_offset_by_dir(t_direction dir)
{
	t_pos	offset;

	if (dir == LEFT)
		offset = get_init_pos_value(-1, 0);
	else if (dir == RIGHT)
		offset = get_init_pos_value(1, 0);
	else if (dir == UP)
		offset = get_init_pos_value(0, -1);
	else if (dir == DOWN)
		offset = get_init_pos_value(0, 1);
	return (offset);
}

static size_t	get_smallest_cost_from_e(t_list *map, t_pos *pos, t_heap *heap)
{
	t_path_node		*lp;
	unsigned short	i;
	size_t			min_e;

	i = 0;
	min_e = SIZE_MAX;
	while (i <= DOWN)
	{
		lp = get_map_value_by_dir(map, (t_direction)i, pos, heap);
		if (!lp)
			continue ;
		if (min_e < lp->dist_e)
			min_e = lp->dist_e;
	}
	return (min_e);
}

static t_path_node
	*get_map_value_by_dir(t_list *map, t_direction dir,
	t_pos *pos, t_heap *heap)
{
	t_pos	offset;
	t_list	*lp;
	t_list	*lhp;

	offset = get_offset_by_dir(dir);
	lp = ft_lstget_idx(map, pos->x + offset.x - 1);
	if (!lp)
		return (NULL);
	if (*(((char *)lp->content) + pos->y + offset.y - 1) == SL_MAP_WALL
		|| *(((char *)lp->content) + pos->y + offset.y - 1) == NULL)
		return (NULL);
	lhp = ft_lstchr(heap->lst, lstchr_vpm, ((t_path_node *)lp->content)->pos);
	if (lhp != NULL)
	{
		push_heap(heap, init_path_node_value_ptr(
				0, 0.0, ((t_path_node *)lp->content)->pos), eval_path_node);
		lhp = ft_lstchr(heap->lst, lstchr_vpm,
				((t_path_node *)lp->content)->pos);
	}
	return ((t_path_node *)lhp->content);
}

static bool	
	update_neighbors_dist(t_list *map, t_pos *pos, t_pos *dest, t_heap *heap)
{
	t_path_node		*lp;
	unsigned short	i;
	bool			is_exist;

	i = 0;
	is_exist = false;
	while (i <= DOWN)
	{
		lp = get_map_value_by_dir(map, (t_direction)i, pos, heap);
		if (!lp)
			continue ;
		is_exist = true;
		lp->dist_s = get_heuristic_cost(dest, lp->pos);
		lp->dist_e = get_smallest_cost_from_e(map, lp->pos, heap);
	}
	return (is_exist);
}

bool	verify_path_map(t_list *map)
{
	t_heap	heap;
	t_pos	*pos_e;
	t_pos	*pos_s;
	bool	flag;

	pos_e = get_object_pos_map(map, SL_MAP_PERSON);
	pos_s = get_object_pos_map(map, SL_MAP_EXIT);
	heap = init_heap();
	flag = false;
	push_heap(&heap, init_path_node_value_ptr(0,
			get_heuristic_cost(pos_s, pos_e), pos_e), eval_path_node);
	while (flag == false)
	{
		if (update_neighbors_dist(map, ((t_path_node *)heap.lst->content)->pos,
				pos_s, &heap) == false)
			return (false); // free values
	}
	return (true); // free values
}
