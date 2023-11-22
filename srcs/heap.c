/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:32:26 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/22 03:15:59 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_heap.h"

static void	swap_element_heap(t_list *lsta, t_list *lstb)
{
	void	*tmp;

	tmp = lsta->content;
	lsta->content = lstb->content;
	lstb->content = tmp;
}

t_heap	init_heap(void)
{
	t_heap	heap;

	heap.count = 0;
	heap.lst = NULL;
	return (heap);
}

static void	exec_while_pop_heap(t_heap *heap, size_t *parent, size_t *child)
{
	swap_element_heap(ft_lstget_idx(heap->lst, *child - 1),
		ft_lstget_idx(heap->lst, *parent - 1));
	*parent = *child;
	*child = *parent * 2;
	if (*child + 1 <= heap->count - 1)
		if (ft_lstget_idx(heap->lst, *child - 1)
			< ft_lstget_idx(heap->lst, *child))
			*child += 1;
}

void	*pop_heap(t_heap *heap, size_t (*eval)(void *))
{
	void	*val;
	size_t	parent;
	size_t	child;
	t_list	*tp;

	if (heap->count == 0)
		return (NULL);
	val = heap->lst->content;
	swap_element_heap(heap->lst, ft_lstget_idx(heap->lst, heap->count - 1));
	heap->count -= 1;
	ft_dellast(&heap->lst, NULL);
	if (heap->count == 0)
		return (val);
	parent = 1;
	child = parent * 2;
	if (child + 1 <= heap->count)
	{
		tp = ft_lstget_idx(heap->lst, child - 1);
		if (eval(tp->content) > eval(tp->next->content))
			child++;
	}
	while (child <= heap->count && eval(ft_lstget_idx(heap->lst, child - 1))
		< eval(ft_lstget_idx(heap->lst, parent - 1)))
		exec_while_pop_heap(heap, &parent, &child);
	return (val);
}

void	push_heap(t_heap *heap, void *value, size_t (*eval)(void *))
{
	size_t	child;
	size_t	parent;

	ft_lstadd_back(&heap->lst, ft_lstnew(value));
	heap->count++;
	child = heap->count;
	parent = child / 2;
	while (child > 1 && eval(ft_lstget_idx(heap->lst, child - 1))
		< eval(ft_lstget_idx(heap->lst, parent - 1)))
	{
		swap_element_heap(ft_lstget_idx(heap->lst, child - 1),
			ft_lstget_idx(heap->lst, parent - 1));
		child = parent;
		parent = child / 2;
	}
}
