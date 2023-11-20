/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:50 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 22:57:12 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "so_long.h"

typedef struct s_pos {
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_gamedat {
	t_pos	*userpos;
}	t_gamedat;

typedef struct s_mlxvars {
	void		*mlx;
	void		*mlx_win;
	t_list		*imgs;
	t_gamedat	*gamedat;
}	t_mlxvars;

#endif