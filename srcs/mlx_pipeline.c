/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_pipeline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:02:57 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 16:45:58 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_manager(int key, t_mlxvars *p)
{
	if (key == SL_KEY_ESC)
	{
		if (free_mlx(p) == FALSE)
			exit(EXIT_FAILURE);
		else
			exit(EXIT_SUCCESS);
	}
	return (0);
}

static BOOL	maps_pipeline(t_mlxvars *vars)
{
	t_list	*map;

	(void)vars;
	map = read_map("maps/level1.ber");
	if (verify_wall_map(map) == FALSE
		|| verify_elements_in_map(map) == FALSE
		|| verify_path_map(map) == FALSE)
	{
		ft_lstclear(&map, free);
		return (FALSE);
	}
	return (TRUE);
}

BOOL	mlx_pipeline(t_mlxvars *vars)
{
	if (maps_pipeline(vars) == FALSE)
		return (FALSE);
	ft_printf("Hello\n");
	mlx_key_hook(vars->mlx_win, key_manager, &vars);
	mlx_loop(vars->mlx);
	return (TRUE);
}
