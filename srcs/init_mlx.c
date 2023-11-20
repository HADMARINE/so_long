/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:56:00 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 17:26:52 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlxvars	init_mlxvars(void)
{
	t_mlxvars	vars;

	vars.mlx = NULL;
	vars.mlx_win = NULL;
	vars.imgs = NULL;
	// TODO : initialize gamedat
	// vars.gamedat = NULL;
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
