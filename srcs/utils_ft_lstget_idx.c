/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_lstget_idx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:23:14 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 15:26:49 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstget_idx(t_list *lst, size_t idx)
{
	size_t	i;

	i = 0;
	while (i < idx)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}
