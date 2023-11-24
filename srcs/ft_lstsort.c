/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:56:49 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/24 15:33:47 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_lstsort(t_list *lst, bool(*f)(void *, void *))
{
	t_list	*lp;
	void	*tmp;

	lp = lst;
	while (lp->next != NULL)
	{
		if (f(lp->content, lp->next->content) == true)
		{
			tmp = lp->content;
			lp->content = lp->next->content;
			lp->next->content = tmp;
		}
		lp = lp->next;
	}
}
