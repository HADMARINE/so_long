/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:32:47 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/24 15:26:09 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_mlxvars	vars;

	vars = init_mlxvars();
	if (mlx_pipeline(&vars) == false)
	{
		ft_printf("Error\n");
		if (free_mlx(&vars) == false)
		{
			ft_printf("Error with free\n");
		}
		exit(EXIT_FAILURE);
	}
	return (0);
}
