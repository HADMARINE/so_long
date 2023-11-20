/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_wall_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:10:09 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 16:26:15 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static BOOL	verify_horizontal_wall_map(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) != SL_MAP_WALL)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

BOOL	verify_wall_map(t_list *map)
{
	int		i;
	int		limit;
	t_list	*stash;

	if (verify_horizontal_wall_map((char *)map->content) == FALSE
		|| verify_horizontal_wall_map((char *)(ft_lstlast(map)->content))
		== FALSE)
		return (FALSE);
	i = 1;
	limit = ft_lstsize(map) - 1;
	while (i < limit)
	{
		stash = ft_lstget_idx(map, i);
		if (*((char *)stash->content) != SL_MAP_WALL
			|| *((char *)stash->content + ft_strlen((char *)stash->content) - 1)
			!= SL_MAP_WALL)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
