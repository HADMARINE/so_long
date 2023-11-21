/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_elements_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:07:42 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/21 16:03:43 by lhojoon          ###   ########.fr       */
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

static bool	verify_element(char value, t_elements_map *elements)
{
	if (value == SL_MAP_ITEM)
	{
		elements->item = true;
		return (true);
	}
	if (value == SL_MAP_EXIT)
	{
		if (elements->exit == true)
			return (false);
		elements->exit = true;
		return (true);
	}
	if (value == SL_MAP_PERSON)
	{
		if (elements->person == true)
			return (false);
		elements->person = true;
		return (true);
	}
	if (value != SL_MAP_BLANK && value != SL_MAP_WALL)
		return (false);
	return (true);
}

bool	verify_elements_in_map(t_list *map)
{
	t_elements_map	elements;
	size_t			i;
	size_t			hlen;

	elements = init_elements_map();
	hlen = ft_strlen((char *)map->content);
	map = map->next;
	while (map->next != NULL)
	{
		i = 1;
		while (i < hlen - 1)
		{
			if (verify_element(*((char *)map->content + i), &elements) == false)
				return (false);
			i++;
		}
		map = map->next;
	}
	if (elements.exit == false || elements.item == false
		|| elements.person == false)
		return (false);
	return (true);
}
