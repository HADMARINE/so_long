/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_path_map_ext2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:50:04 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/24 14:50:38 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	free_and_go_lst_vpm(bool value, t_list *lst, t_pos *pos_e, t_pos *pos_s)
{
	t_list	*lp;

	(void)pos_e;
	if (lst != NULL)
	{
		lp = lst;
		while (lp != NULL)
		{
			if (lp->content != NULL)
			{
				if (((t_path_node *)lp->content)->pos != NULL)
					free(((t_path_node *)lp->content)->pos);
				free(lp->content);
			}
			lst = lp->next;
			free(lp);
			lp = lst;
		}
	}
	if (pos_s != NULL)
		free(pos_s);
	return (value);
}
