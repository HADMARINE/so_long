/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:53:41 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/10 14:33:34 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*e;

	e = (t_list *)malloc(sizeof(t_list));
	if (!e)
		return (NULL);
	e->content = content;
	e->next = NULL;
	return (e);
}
