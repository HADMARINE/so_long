/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:19:50 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/17 17:01:37 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>

typedef struct s_mlxvars {
	void	*mlx;
	void	*mlx_win;
}	t_mlxvars;

typedef struct s_pos {
	size_t	x;
	size_t	y;
}	t_pos;

#endif