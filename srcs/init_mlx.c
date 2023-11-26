/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:56:00 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/26 18:32:39 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_gamedat	get_init_gamedat(void)
{
	t_gamedat	vars;

	vars.userpos = get_init_pos();
	vars.size = get_init_pos();
	vars.item_count = 0;
	vars.move_count = 0;
	return (vars);
}

t_mlxvars	get_init_mlxvars(void)
{
	t_mlxvars	vars;

	vars.mlx = NULL;
	vars.mlx_win = NULL;
	vars.imgs = NULL;
	vars.gamedat = get_init_gamedat();
	vars.canvas = NULL;
	return (vars);
}

t_mlxvars	init_mlxvars(void)
{
	t_mlxvars	vars;

	vars = get_init_mlxvars();
	vars.mlx = mlx_init();
	if (!vars.mlx)
		exit(EXIT_FAILURE);
	return (vars);
}
