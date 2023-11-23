/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 12:59:21 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/23 09:00:14 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*ft_lstchr(t_list *lst, bool(*chr)(void *, void *), void *dat)
{
	t_list	*lp;

	lp = lst;
	while (lp != NULL)
	{
		if (chr(lp->content, dat) == true)
			return (lp);
		lp = lp->next;
	}
	return (NULL);
}
