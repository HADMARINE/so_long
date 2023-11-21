/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:56:00 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/21 15:33:44 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_pos	get_init_pos(void)
{
	t_pos	vars;

	vars.x = 0;
	vars.y = 0;
	return (vars);
}

t_gamedat	get_init_gamedat(void)
{
	t_gamedat	vars;

	vars.userpos = get_init_pos();
	return (vars);
}

t_mlxvars	get_init_mlxvars(void)
{
	t_mlxvars	vars;

	vars.mlx = NULL;
	vars.mlx_win = NULL;
	vars.imgs = NULL;
	vars.gamedat = get_init_gamedat();
	return (vars);
}

t_mlxvars	init_mlxvars(void)
{
	t_mlxvars	vars;

	vars = get_init_mlxvars();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	vars.mlx_win = mlx_new_window(vars.mlx,
			SL_WINDOW_SIZE_W, SL_WINDOW_SIZE_H, SL_PROGRAM_NAME);
	if (!vars.mlx_win)
	{
		free_mlx(&vars);
		exit(EXIT_FAILURE);
	}
	return (vars);
}
