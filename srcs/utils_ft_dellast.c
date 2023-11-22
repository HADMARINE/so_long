/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_ft_dellast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 02:02:35 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/22 03:09:41 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

// TODO : A tester
void	ft_dellast(t_list **lst, void (*del)(void *))
{
	t_list	*lp;

	if (lst == NULL)
		return ;
	if ((*lst)->next == NULL)
	{
		if (del)
			del((*lst)->content);
		free(*lst);
		lst = NULL;
		return ;
	}
	lp = *lst;
	while (lp->next->next != NULL)
	{
		lp = lp->next;
	}
	if (del != NULL)
		del(lp->next->content);
	free(lp->next);
	lp->next = NULL;
}
