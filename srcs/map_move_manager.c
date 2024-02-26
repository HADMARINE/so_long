/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_move_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:28:11 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/26 13:14:27 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	e_blank(t_mlxvars *vars, t_pos *newpos)
{
	char	tmp;

	tmp = *((char *)(ft_lstget_idx(vars->map,
					vars->gamedat.userpos->y)->content)
			+ vars->gamedat.userpos->x);
	*((char *)(ft_lstget_idx(vars->map,
			vars->gamedat.userpos->y)->content)
			+ vars->gamedat.userpos->x)
		= *((char *)(ft_lstget_idx(vars->map,
					newpos->y)->content)
			+ newpos->x);
	*((char *)(ft_lstget_idx(vars->map,
			newpos->y)->content)
			+ newpos->x) = tmp;
	vars->gamedat.userpos->x = newpos->x;
	vars->gamedat.userpos->y = newpos->y;
}

static void	e_exit(t_mlxvars *vars)
{
	if (vars->gamedat.item_count != 0)
	{
		return ;
	}
	ft_printf("You escaped ! Moves : %d\n", vars->gamedat.move_count + 1);
	free_mlx(vars);
	exit(EXIT_SUCCESS);
}

static void	e_wall(t_mlxvars *vars)
{
	(void)vars;
}

static void	e_item(t_mlxvars *vars, t_pos *newpos)
{
	*((char *)(ft_lstget_idx(vars->map,
			newpos->y)->content)
			+ newpos->x)
		= *((char *)(ft_lstget_idx(vars->map,
					vars->gamedat.userpos->y)->content)
			+ vars->gamedat.userpos->x);
	*((char *)(ft_lstget_idx(vars->map,
			vars->gamedat.userpos->y)->content)
			+ vars->gamedat.userpos->x)
		= SL_MAP_BLANK;
	vars->gamedat.item_count--;
	vars->gamedat.userpos->x = newpos->x;
	vars->gamedat.userpos->y = newpos->y;
}

void	user_move(t_mlxvars *vars, t_direction dir)
{
	t_pos	newpos;
	t_pos	offset;
	char	*newelem;

	offset = get_offset_by_dir(dir);
	newpos = get_init_pos_value(vars->gamedat.userpos->x + offset.x,
			vars->gamedat.userpos->y + offset.y);
	newelem = ft_lstget_idx(vars->map, newpos.y)->content + newpos.x;
	if (*newelem == SL_MAP_EXIT)
		e_exit(vars);
	else if (*newelem == SL_MAP_WALL)
		e_wall(vars);
	else if (*newelem == SL_MAP_BLANK)
		e_blank(vars, &newpos);
	else if (*newelem == SL_MAP_ITEM)
		e_item(vars, &newpos);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->canvas, 0, 0);
	vars->gamedat.move_count++;
	ft_printf("Moves : %d\n", vars->gamedat.move_count);
}
