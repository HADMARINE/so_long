/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:34:29 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/24 10:58:21 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * lst : entire list
 * new : new element
 * f : function which evaluates value
*/
void	ft_lstadd_sort(t_list **lst, t_list *new, bool(*f)(void *, void *))
{
	ft_lstadd_back(lst, new);
	ft_lstsort(*lst, f);
}
