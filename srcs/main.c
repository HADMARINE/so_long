/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:32:47 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/17 17:04:33 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "libft.h"
#include "definitions.h"
#include "struct.h"
#include <stdio.h>

int	key_manager(int key, void *p)
{
	if (key == SL_KEY_ESC)
		exit(0);
	(void)p;
	return (0);
}

int	main(void)
{
	t_mlxvars	vars;

	vars.mlx = mlx_init();
	vars.mlx_win = mlx_new_window(vars.mlx,
			SL_WINDOW_SIZE_W, SL_WINDOW_SIZE_H, "Hello world!");
	mlx_key_hook(vars.mlx_win, key_manager, &vars);
	mlx_loop(vars.mlx);
}
