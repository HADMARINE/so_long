/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_elements_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:07:42 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 16:45:52 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static t_elements_map	init_elements_map(void)
{
	t_elements_map	map;

	map.exit = FALSE;
	map.item = FALSE;
	map.person = FALSE;
	return (map);
}

BOOL	verify_elements_in_map(t_list *map)
{
	t_elements_map	elements;
	size_t			i;
	size_t			hlen;

	elements = init_elements_map();
	hlen = ft_strlen((char *)map->content);
	while (map->next != NULL)
	{
		i = 1;
		while (i < hlen - 1)
		{
			if (*((char *)map->content + i) == SL_MAP_ITEM)
				elements.item = TRUE;
			if (*((char *)map->content + i) == SL_MAP_EXIT)
				elements.exit = TRUE;
			if (*((char *)map->content + i) == SL_MAP_PERSON)
				elements.person = TRUE;
			i++;
		}
		map = map->next;
	}
	if (elements.exit == FALSE || elements.item == FALSE
		|| elements.person == FALSE)
		return (FALSE);
	return (TRUE);
}
