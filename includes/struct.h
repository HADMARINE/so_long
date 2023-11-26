/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:50 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/26 18:32:24 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <X11/Xlib.h>
# include <X11/extensions/XShm.h>

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

typedef struct s_gamedat {
	t_pos	userpos;
	t_pos	size;
	size_t	item_count;
	size_t	move_count;
}	t_gamedat;

typedef struct s_mlximage {
	XImage			*image;
	Pixmap			pix;
	GC				gc;
	int				size_line;
	int				bpp;
	int				width;
	int				height;
	int				type;
	int				format;
	char			*data;
	XShmSegmentInfo	shm;
}	t_mlximage;

typedef struct s_mlxvars {
	void		*mlx;
	void		*mlx_win;
	t_list		*imgs;
	t_gamedat	gamedat;
	t_list		*map;
	t_mlximage	*canvas;
}	t_mlxvars;

/**
 * dist_e 	: distance from entry
 * dist_s	: distance heuristic to destination (sortie)
 * pos		: position, coordination
*/
typedef struct s_path_node {
	size_t	dist_e;
	double	dist_s;
	bool	went;
	t_pos	*pos;

}	t_path_node;

typedef enum e_direction {
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3
}	t_direction;

t_pos		get_init_pos(void);
t_pos		get_init_pos_value(int x, int y);
t_pos		*get_init_pos_ptr(void);
t_pos		*get_init_pos_ptr_value(int x, int y);
t_gamedat	get_init_gamedat(void);
t_mlxvars	get_init_mlxvars(void);
t_path_node	init_path_node(void);
t_path_node	*init_path_node_value_ptr(size_t e,
				double s, t_pos *pos, bool went);

#endif