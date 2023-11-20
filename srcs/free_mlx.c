/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:58:49 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 15:17:03 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	img_lst_clear(t_list **lst, t_mlxvars *vars)
{
	t_list	*lp;
	t_list	*lp2;

	if (!lst || !vars)
		return ;
	lp = *lst;
	while (lp)
	{
		mlx_destroy_image(vars->mlx, lp->content);
		lp2 = lp->next;
		free(lp);
		lp = lp2;
	}
	*lst = NULL;
}

BOOL	free_mlx(t_mlxvars *p)
{
	if (p->mlx == NULL)
		return (FALSE);
	if (p->mlx_win)
	{
		mlx_destroy_window(p->mlx, p->mlx_win);
		p->mlx_win = NULL;
	}
	mlx_destroy_display(p->mlx);
	free(p->mlx);
	p->mlx = NULL;
	if (p->imgs)
	{
		img_lst_clear(&(p->imgs), p);
	}
	return (TRUE);
}
