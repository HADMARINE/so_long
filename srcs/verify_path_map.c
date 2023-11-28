/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 16:10:55 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 14:00:42 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void			*free_and_go_vpm(t_pos *pos);
bool			free_and_go_lst_vpmo(bool value, t_list *lst);
t_pos			get_offset_by_dir(t_direction dir);
bool			eval_path_node(void *node1, void *node2);
bool			lstchr_vpm(void *val, void *dat);
double			get_heuristic_cost(t_pos *dest, t_pos *pos);
t_path_node		*get_map_value_by_dir(t_list *map, t_direction dir,
					t_pos *pos, t_list **lst);
t_path_node		*get_map_value_by_dir_no_creation(t_list *map, t_direction dir,
					t_pos *pos, t_list *lst);

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

	i = 0;
	is_exist = false;
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
	return (is_exist);
}

static bool	verify_path_map_one(t_list *map, t_pos *pos_e, t_pos *pos_s)
{
	t_list		*lst;
	bool		flag;

	flag = false;
	lst = ft_lstnew(init_path_node_value_ptr(0,
				get_heuristic_cost(pos_s, pos_e), pos_e, false));
	while (flag == false)
	{
		if (update_neighbors_dist(map, ((t_path_node *)lst->content)->pos,
				pos_s, &lst) == false)
			return (free_and_go_lst_vpmo(false, lst));
		if (((t_path_node *)lst->content)->pos->x == pos_s->x
			&& ((t_path_node *)lst->content)->pos->y == pos_s->y)
			return (free_and_go_lst_vpmo(true, lst));
		if (((t_path_node *)lst->content)->went == true)
			return (free_and_go_lst_vpmo(false, lst));
		((t_path_node *)lst->content)->went = true;
		ft_lstsort(lst, eval_path_node);
	}
	return (free_and_go_lst_vpmo(true, lst));
}

static bool	free_and_go_main_vpm(bool value, t_list **lst,
		t_pos *pos_e, t_pos *pos_s)
{
	(void)lst;
	if (lst)
		ft_lstclear(lst, free);
	if (pos_e)
		free(pos_e);
	if (pos_s)
		free(pos_s);
	return (value);
}

bool	verify_path_map(t_mlxvars *vars)
{
	t_pos	*pos_e;
	t_pos	*pos_s;
	t_list	*items_lst;
	t_list	*ilp;

	pos_e = get_object_pos_map(vars->map, SL_MAP_PERSON);
	pos_s = get_object_pos_map(vars->map, SL_MAP_EXIT);
	if (pos_e == NULL || pos_s == NULL)
		return (free_and_go_main_vpm(false, NULL, pos_e, pos_s));
	if (verify_path_map_one(vars->map, pos_e, pos_s) == false)
		return (free_and_go_main_vpm(false, NULL, pos_e, pos_s));
	items_lst = get_object_pos_list_map(vars->map, SL_MAP_ITEM);
	if (items_lst == NULL)
		return (free_and_go_main_vpm(false, &items_lst, pos_e, pos_s));
	vars->gamedat.item_count = ft_lstsize(items_lst);
	ilp = items_lst;
	while (ilp != NULL)
	{
		if (verify_path_map_one(vars->map, pos_e, ilp->content) == false
			|| verify_path_map_one(vars->map, ilp->content, pos_s) == false)
			return (free_and_go_main_vpm(false, &items_lst, pos_e, pos_s));
		ilp = ilp->next;
	}
	return (free_and_go_main_vpm(true, &items_lst, pos_e, pos_s));
}
