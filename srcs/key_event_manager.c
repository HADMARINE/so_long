/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:40:02 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/26 23:04:41 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "manager.h"

int	key_event_manager(int key, t_mlxvars *p)
{
	if (key == SL_KEY_ESC)
	{
		if (free_mlx(p) == false)
			exit(EXIT_FAILURE);
		else
			exit(EXIT_SUCCESS);
	}
	else if (key == SL_KEY_W)
		user_move(p, UP);
	else if (key == SL_KEY_A)
		user_move(p, LEFT);
	else if (key == SL_KEY_S)
		user_move(p, DOWN);
	else if (key == SL_KEY_D)
		user_move(p, RIGHT);
	return (0);
}
