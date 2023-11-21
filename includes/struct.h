/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:50 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/21 17:03:27 by lhojoon          ###   ########.fr       */
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

t_pos		get_init_pos(void);
t_gamedat	get_init_gamedat(void);
t_mlxvars	get_init_mlxvars(void);

#endif