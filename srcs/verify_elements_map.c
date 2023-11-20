/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_elements_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:07:42 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 23:06:10 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maps.h"

static t_elements_map	init_elements_map(void)
{
	t_elements_map	map;

	map.exit = false;
	map.item = false;
	map.person = false;
	return (map);
}

bool	verify_elements_in_map(t_list *map)
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
				elements.item = true;
			if (*((char *)map->content + i) == SL_MAP_EXIT)
				elements.exit = true;
			if (*((char *)map->content + i) == SL_MAP_PERSON)
				elements.person = true;
			i++;
		}
		map = map->next;
	}
	if (elements.exit == false || elements.item == false
		|| elements.person == false)
		return (false);
	return (true);
}
