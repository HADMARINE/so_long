/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 17:37:52 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/25 20:25:54 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static t_sl_img_keys	get_img_key_by_map_element(char e)
{
	if (e == SL_MAP_EXIT)
		return (SL_IMG_KEYS_EXIT);
	if (e == SL_MAP_PERSON)
		return (SL_IMG_KEYS_PERSON);
	if (e == SL_MAP_ITEM)
		return (SL_IMG_KEYS_ITEM);
	return (100);
}

static void	draw_element(t_mlxvars *vars, int x, int y)
{
	t_sl_img_keys	key;

	key = get_img_key_by_map_element(
			*((char *)ft_lstget_idx(vars->map, y)->content + x));
	if (key == 100)
		return ;
	draw_square(vars, get_image_by_key(vars,
			key),
		x * SL_IMG_SIZE, y * SL_IMG_SIZE);
}

void	draw_map(t_mlxvars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (y < vars->gamedat.size.y)
	{
		x = 0;
		while (x < vars->gamedat.size.x)
		{
			if (*((char *)ft_lstget_idx(vars->map, y)->content + x)
				== SL_MAP_WALL)
				draw_square(vars, get_image_by_key(vars, SL_IMG_KEYS_WALL),
					x * SL_IMG_SIZE, y * SL_IMG_SIZE);
			else
			{
				draw_square(vars, get_image_by_key(vars, SL_IMG_KEYS_BLANK),
					x * SL_IMG_SIZE, y * SL_IMG_SIZE);
				draw_element(vars, x, y);
			}
			x++;
		}
		y++;
	}
}
