/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:32:47 by lhojoon           #+#    #+#             */
/*   Updated: 2024/02/02 17:45:49 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char *argv[])
{
	t_mlxvars	vars;

	if (argc != 2)
	{
		ft_printf("Error - no args\n");
		exit(EXIT_FAILURE);
	}
	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".ber", 4) != 0)
	{
		ft_printf("Error - .ber\n");
		exit(EXIT_FAILURE);
	}
	vars = init_mlxvars();
	vars.map_path = argv[1];
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
