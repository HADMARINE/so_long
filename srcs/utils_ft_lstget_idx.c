/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_lstget_idx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:23:14 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/23 09:21:47 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstget_idx(t_list *lst, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		if (lst->next == NULL)
			return (NULL);
		lst = lst->next;
		i++;
	}
	return (lst);
}
