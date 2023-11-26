/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_map_ext2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:50:04 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/26 18:23:16 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*free_and_go_vpm(t_pos *pos);
t_pos	get_offset_by_dir(t_direction dir);
bool	eval_path_node(void *node1, void *node2);
bool	lstchr_vpm(void *val, void *dat);
double	get_heuristic_cost(t_pos *dest, t_pos *pos);

bool	free_and_go_lst_vpmo(bool value, t_list *lst)
{
	t_list	*lp;

	if (lst != NULL)
	{
		lp = lst;
		while (lp != NULL)
		{
			if (lp->content != NULL)
			{
				if (((t_path_node *)lp->content)->pos != NULL)
					free(((t_path_node *)lp->content)->pos);
				free(lp->content);
			}
			lst = lp->next;
			free(lp);
			lp = lst;
		}
	}
	return (value);
}

t_path_node
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
	free(newpos);
	return ((t_path_node *)lp->content);
}

t_path_node
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
