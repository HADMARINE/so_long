/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:32:47 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/23 09:09:24 by lhojoon          ###   ########.fr       */
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

// size_t	eval(void *v)
// {
// 	return (*(size_t *)v);
// }

// int	main(void)
// {
// 	t_heap	heap;
// 	int *a = (int *)malloc(sizeof(int));
// 	int *b =  (int *)malloc(sizeof(int));
// 	int *c =  (int *)malloc(sizeof(int));

// 	*a = 1;
// 	*b = 2;
// 	*c = 3;

// 	heap = init_heap();
// 	push_heap(&heap, a, eval);
// 	push_heap(&heap, b, eval);
// 	push_heap(&heap, c, eval);

// 	// int *d = (int *)pop_heap(&heap, eval);
// 	// int *d = heap.lst->content;
// 	// ft_printf("%d", *d);
// 	ft_printf("%d", *(int *)pop_heap(&heap, eval));
// 	ft_printf("%d", *(int *)pop_heap(&heap, eval));
// 	ft_printf("%d", *(int *)pop_heap(&heap, eval));
// }
