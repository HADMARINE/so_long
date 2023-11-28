/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_get_object_pos_list_map.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 23:09:34 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/28 13:07:21 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static void	init_get_object_pos_list_map_values(
	int *y, t_list **mapp, t_list *map, t_list **pos_list)
{
	*y = 1;
	*mapp = map->next;
	*pos_list = NULL;
}

static bool	put_pos_goplm(t_list **pos_list, int x, int y)
{
	t_pos	*pos;

	pos = get_init_pos_ptr();
	if (!pos)
	{
		ft_lstclear(pos_list, free);
		return (false);
	}
	pos->x = (size_t)x;
	pos->y = (size_t)y;
	ft_lstadd_back(pos_list, ft_lstnew(pos));
	return (true);
}

/**
 * Get objects' position of map
 * returns t_list * (free obliged value)
 * returns NULL when malloc error or not found
*/
t_list	*get_object_pos_list_map(t_list *map, char element)
{
	t_list	*mapp;
	t_list	*pos_list;
	int		y;
	int		x;

	init_get_object_pos_list_map_values(&y, &mapp, map, &pos_list);
	while (mapp->next != NULL)
	{
		x = 1;
		while (*((char *)mapp->content + x))
		{
			if (*((char *)mapp->content + x) == element)
			{
				if (put_pos_goplm(&pos_list, x, y) == false)
					return (NULL);
			}
			x++;
		}
		mapp = mapp->next;
		y++;
	}
	return (pos_list);
}

/**
 * Get ONE object position of map (first occurence)
 * returns t_list * (free obliged value)
 * returns NULL when malloc error or not found
*/
t_pos	*get_object_pos_map(t_list *map, char element)
{
	t_pos	*pos;
	t_list	*mapp;

	pos = get_init_pos_ptr_value(0, 1);
	if (!pos)
		return (NULL);
	mapp = map->next;
	while (mapp->next != NULL)
	{
		pos->x = 1;
		while (*((char *)mapp->content + pos->x))
		{
			if (*((char *)mapp->content + pos->x) == element)
				return (pos);
			pos->x++;
		}
		mapp = mapp->next;
		pos->y++;
	}
	return (NULL);
}
