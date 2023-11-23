/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:08:02 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/23 08:56:31 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGES_H
# define IMAGES_H

# include "struct.h"

t_mlximage	get_init_image(t_mlxvars *vars, int w, int h);
t_mlximage	get_new_sprite_image(t_mlxvars *vars, char *path);

#endif