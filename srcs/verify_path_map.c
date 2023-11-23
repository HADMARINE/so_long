/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:55 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/23 17:43:42 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * Get heuristic cost to reach dest from pos
 * Using Pytagorath theorem (Manhattan)
 * dest : destination
 * pos : current position
 */
static double	get_heuristic_cost(t_pos *dest, t_pos *pos)
{
	return (sqrt(abs(dest->x - pos->x) + abs(dest->y - pos->y)));
}

/**
 * val : t_path_node
 * dat : t_pos
*/
static bool	lstchr_vpm(void *val, void *dat)
{
	if (((t_path_node *)val)->pos->x == ((t_pos *)dat)->x
		&& ((t_path_node *)val)->pos->y == ((t_pos *)dat)->y)
		return (true);
	return (false);
}

static bool	eval_path_node(void *node1, void *node2)
{
	// if (((t_path_node *)node1)->went == false && ((t_path_node *)node2)->went == true)
	// 	return (true);
	if (((t_path_node *)node1)->dist_e + ((t_path_node *)node1)->dist_s
		> ((t_path_node *)node2)->dist_e + ((t_path_node *)node2)->dist_s)
		return (true);
	if (((t_path_node *)node1)->dist_e + ((t_path_node *)node1)->dist_s
		== ((t_path_node *)node2)->dist_e + ((t_path_node *)node2)->dist_s)
	{
		if (((t_path_node *)node1)->dist_e > ((t_path_node *)node2)->dist_e)
			return (true);
		return (false);
	}
	return (false);
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
	else
		offset = get_init_pos_value(0, 1);
	return (offset);
}

static void	*free_and_go_vpm(t_pos *pos)
{
	free(pos);
	return (NULL);
}

static t_path_node
	*get_map_value_by_dir(t_list *map, t_direction dir,
	t_pos *pos, t_heap *heap)
{
	t_pos	offset;
	t_list	*lp;
	t_pos	*newpos;

	offset = get_offset_by_dir(dir);
	newpos = get_init_pos_ptr_value(pos->x + offset.x, pos->y + offset.y);
	if (newpos == NULL)
		return (NULL);
	lp = ft_lstget_idx(map, newpos->y);
	if (!lp)
		return (free_and_go_vpm(newpos));
	if (*(((char *)lp->content) + newpos->x) == SL_MAP_WALL
		|| *(((char *)lp->content) + newpos->x) == '\0')
		return (free_and_go_vpm(newpos));
	lp = ft_lstchr(heap->lst, lstchr_vpm, newpos);
	if (lp == NULL)
	{
		push_heap(heap, init_path_node_value_ptr(
				INT32_MAX, (double)INT32_MAX, newpos, false), eval_path_node);
		lp = ft_lstchr(heap->lst, lstchr_vpm, newpos);
	}
	return ((t_path_node *)lp->content);
}

static t_path_node
	*get_map_value_by_dir_no_creation(t_list *map, t_direction dir,
	t_pos *pos, t_heap *heap)
{
	t_pos	offset;
	t_list	*lp;
	t_pos	*newpos;

	offset = get_offset_by_dir(dir);
	newpos = get_init_pos_ptr_value(pos->x + offset.x, pos->y + offset.y);
	if (newpos == NULL)
		return (NULL);
	lp = ft_lstget_idx(map, newpos->y);
	if (!lp)
		return (free_and_go_vpm(newpos));
	if (*(((char *)lp->content) + newpos->x) == SL_MAP_WALL
		|| *(((char *)lp->content) + newpos->x) == '\0')
		return (free_and_go_vpm(newpos));
	lp = ft_lstchr(heap->lst, lstchr_vpm, newpos);
	if (lp == NULL)
		return (free_and_go_vpm(newpos));
	return ((t_path_node *)lp->content);
}

static size_t	get_smallest_cost_from_e(
		t_list *map, t_pos *pos, t_heap *heap)
{
	t_path_node		*lp;
	unsigned short	i;
	size_t			min_e;

	i = 0;
	min_e = INT32_MAX;
	while (i <= DOWN)
	{
		lp = get_map_value_by_dir_no_creation(map, (t_direction)i++, pos, heap);
		if (!lp)
			continue ;
		if (min_e > lp->dist_e)
			min_e = lp->dist_e;
	}
	return (min_e);
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
		i++;
		if (!lp)
			continue ;
		is_exist = true;
		if (lp->dist_e != 0)
		{
			lp->dist_s = get_heuristic_cost(dest, lp->pos);
			lp->dist_e = get_smallest_cost_from_e(map, lp->pos, heap) + 1;
		}
	}
	return (is_exist);
}
#include <stdio.h>

bool	verify_path_map(t_list *map)
{
	t_heap	heap;
	t_pos	*pos_e;
	t_pos	*pos_s;
	bool	flag;
	// t_list	*lp;
	// t_path_node	*pnp;

	pos_e = get_object_pos_map(map, SL_MAP_PERSON);
	pos_s = get_object_pos_map(map, SL_MAP_EXIT);
	heap = init_heap();
	flag = false;
	push_heap(&heap, init_path_node_value_ptr(0,
			get_heuristic_cost(pos_s, pos_e), pos_e, true), eval_path_node);
	while (flag == false)
	{
		printf("count : %zu x : %d  y : %d dist_e : %zu dist_s : %f\n", heap.count,
			((t_path_node *)heap.lst->content)->pos->x,
			((t_path_node *)heap.lst->content)->pos->y,
			((t_path_node *)heap.lst->content)->dist_e,
			((t_path_node *)heap.lst->content)->dist_s);
		if (update_neighbors_dist(map, ((t_path_node *)heap.lst->content)->pos,
				pos_s, &heap) == false)
			return (false); // free values
		if (((t_path_node *)heap.lst->content)->pos->x == pos_s->x
			&& ((t_path_node *)heap.lst->content)->pos->y == pos_s->y)
			return (true); // free values
		((t_path_node *)heap.lst->content)->went = true;
		// if (lp == heap.lst->content)
		// {
		// 	pnp = (t_path_node *)pop_heap(&heap, eval_path_node);
		// 	pnp->dist_e = 1000000;
		// 	push_heap(&heap, pnp, eval_path_node);
		// }
		// lp = heap.lst->content;
	}
	return (true); // free values
}
