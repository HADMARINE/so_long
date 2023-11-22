/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 01:31:20 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/22 02:42:09 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HEAP_H
# define FT_HEAP_H

# include "so_long.h"

typedef struct s_heap {
	t_list	*lst;
	size_t	count;
}	t_heap;

t_heap	init_heap(void);
void	*pop_heap(t_heap *heap, size_t (*eval)(void *));
void	push_heap(t_heap *heap, void *value, size_t (*eval)(void *));


#endif