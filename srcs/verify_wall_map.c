/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_wall_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:10:09 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/23 08:57:46 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static bool	verify_horizontal_wall_map(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != SL_MAP_WALL)
			return (false);
		i++;
	}
	return (true);
}

bool	verify_wall_map(t_list *map)
{
	int		i;
	int		limit;
	t_list	*stash;

	if (verify_horizontal_wall_map((char *)map->content) == false
		|| verify_horizontal_wall_map((char *)(ft_lstlast(map)->content))
		== false)
		return (false);
	i = 1;
	limit = ft_lstsize(map) - 1;
	while (i < limit)
	{
		stash = ft_lstget_idx(map, i);
		if (*((char *)stash->content) != SL_MAP_WALL
			|| *((char *)stash->content + ft_strlen((char *)stash->content) - 1)
			!= SL_MAP_WALL)
			return (false);
		i++;
	}
	return (true);
}
