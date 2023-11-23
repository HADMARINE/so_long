/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:57 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/23 09:10:04 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	maps_pipeline(t_mlxvars *vars)
{
	t_list	*map;

	(void)vars;
	map = read_map("maps/level1.ber");
	if (map == NULL)
		return (false);
	if (verify_wall_map(map) == false
		|| verify_elements_in_map(map) == false
		|| verify_path_map(map) == false)
	{
		ft_lstclear(&map, free);
		return (false);
	}
	return (true);
}

static bool	hook_pipeline(t_mlxvars *vars)
{
	mlx_key_hook(vars->mlx_win, key_event_manager, vars);
	mlx_hook(vars->mlx_win, SL_X11_EVENT_DESTROY_NOTIFY,
		0L, x11_destroy_event, vars);
	return (true);
}

bool	mlx_pipeline(t_mlxvars *vars)
{
	if (maps_pipeline(vars) == false)
		return (false);
	if (hook_pipeline(vars) == false)
		return (false);
	mlx_loop(vars->mlx);
	return (true);
}
