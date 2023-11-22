/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:50 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/22 15:47:14 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "so_long.h"

typedef struct s_pos {
	size_t	x;
	size_t	y;
}	t_pos;

typedef struct s_imgdat {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_imgdat;

typedef struct s_gamedat {
	t_pos	userpos;
}	t_gamedat;

typedef struct s_mlxvars {
	void		*mlx;
	void		*mlx_win;
	t_list		*imgs;
	t_gamedat	gamedat;
}	t_mlxvars;

typedef struct s_mlximage {
	void	*ref;
	t_pos	size;
	char	*pixels;
	int		bpp;
	int		line_size;
	int		endian;
}	t_mlximage;

/**
 * dist_e 	: distance from entry
 * dist_s	: distance heuristic to destination (sortie)
 * pos		: position, coordination
*/
typedef struct s_path_node {
	size_t	dist_e;
	float	dist_s;
	t_pos	*pos;

}	t_path_node;

typedef enum e_direction {
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
}	t_direction;

t_pos		get_init_pos(void);
t_pos		get_init_pos_value(size_t x, size_t y);
t_pos		*get_init_pos_ptr(void);
t_pos		*get_init_pos_ptr_value(size_t x, size_t y);
t_gamedat	get_init_gamedat(void);
t_mlxvars	get_init_mlxvars(void);
t_path_node	init_path_node(void);
t_path_node	*init_path_node_value_ptr(size_t e, float s, t_pos *pos);

#endif