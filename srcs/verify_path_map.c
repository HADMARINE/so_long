/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:55 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/24 14:51:48 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	*free_and_go_vpm(t_pos *pos);
bool	free_and_go_lst_vpm(
			bool value, t_list *lst, t_pos *pos_e, t_pos *pos_s);
t_pos	get_offset_by_dir(t_direction dir);
bool	eval_path_node(void *node1, void *node2);
bool	lstchr_vpm(void *val, void *dat);
double	get_heuristic_cost(t_pos *dest, t_pos *pos);

static t_path_node
	*get_map_value_by_dir(t_list *map, t_direction dir,
	t_pos *pos, t_list **lst)
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
	lp = ft_lstchr(*lst, lstchr_vpm, newpos);
	if (lp == NULL)
	{
		ft_lstadd_sort(lst, ft_lstnew(init_path_node_value_ptr(INT32_MAX,
					(double)INT32_MAX, newpos, false)), eval_path_node);
		lp = ft_lstchr(*lst, lstchr_vpm, newpos);
	}
	else
		free(newpos);
	return ((t_path_node *)lp->content);
}

static t_path_node
	*get_map_value_by_dir_no_creation(t_list *map, t_direction dir,
	t_pos *pos, t_list *lst)
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
	lp = ft_lstchr(lst, lstchr_vpm, newpos);
	if (lp == NULL)
		return (free_and_go_vpm(newpos));
	free(newpos);
	return ((t_path_node *)lp->content);
}

static size_t	get_smallest_cost_from_e(
		t_list *map, t_pos *pos, t_list *lst)
{
	t_path_node		*lp;
	unsigned short	i;
	size_t			min_e;

	i = 0;
	min_e = INT32_MAX;
	while (i <= DOWN)
	{
		lp = get_map_value_by_dir_no_creation(map, (t_direction)i++, pos, lst);
		if (!lp)
			continue ;
		if (min_e > lp->dist_e)
			min_e = lp->dist_e;
	}
	return (min_e);
}

static bool	
	update_neighbors_dist(t_list *map, t_pos *pos, t_pos *dest, t_list **lst)
{
	t_path_node		*lp;
	unsigned short	i;
	bool			is_exist;
	bool			is_new_exist;

	i = 0;
	is_exist = false;
	is_new_exist = true;
	while (i <= DOWN)
	{
		lp = get_map_value_by_dir(map, (t_direction)i, pos, lst);
		i++;
		if (!lp)
			continue ;
		is_exist = true;
		if (lp->dist_e != 0)
		{
			lp->dist_s = get_heuristic_cost(dest, lp->pos);
			lp->dist_e = get_smallest_cost_from_e(map, lp->pos, *lst) + 1;
		}
	}
	return (is_exist && is_new_exist);
}

bool	verify_path_map(t_list *map)
{
	t_list		*lst;
	t_pos		*pos_e;
	t_pos		*pos_s;
	bool		flag;

	pos_e = get_object_pos_map(map, SL_MAP_PERSON);
	pos_s = get_object_pos_map(map, SL_MAP_EXIT);
	flag = false;
	lst = ft_lstnew(init_path_node_value_ptr(0,
				get_heuristic_cost(pos_s, pos_e), pos_e, false));
	while (flag == false)
	{
		if (update_neighbors_dist(map, ((t_path_node *)lst->content)->pos,
				pos_s, &lst) == false)
			return (free_and_go_lst_vpm(false, lst, pos_e, pos_s));
		if (((t_path_node *)lst->content)->pos->x == pos_s->x
			&& ((t_path_node *)lst->content)->pos->y == pos_s->y)
			return (free_and_go_lst_vpm(true, lst, pos_e, pos_s));
		if (((t_path_node *)lst->content)->went == true)
			return (free_and_go_lst_vpm(false, lst, pos_e, pos_s));
		((t_path_node *)lst->content)->went = true;
		ft_lstsort(lst, eval_path_node);
	}
	return (free_and_go_lst_vpm(true, lst, pos_e, pos_s));
}
