/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:57 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/21 00:11:33 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_manager(int key, t_mlxvars *p)
{
	if (key == SL_KEY_ESC)
	{
		if (free_mlx(p) == false)
			exit(EXIT_FAILURE);
		else
			exit(EXIT_SUCCESS);
	}
	return (0);
}

static bool	maps_pipeline(t_mlxvars *vars)
{
	t_list	*map;

	(void)vars;
	map = read_map("maps/level1.ber");
	if (verify_wall_map(map) == false
		|| verify_elements_in_map(map) == false
		|| verify_path_map(map) == false)
	{
		ft_lstclear(&map, free);
		return (false);
	}
	return (true);
}

bool	mlx_pipeline(t_mlxvars *vars)
{
	if (maps_pipeline(vars) == false)
		return (false);
	mlx_key_hook(vars->mlx_win, key_manager, vars);
	mlx_loop(vars->mlx);
	return (true);
}
