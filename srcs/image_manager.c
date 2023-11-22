/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:01:31 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/21 23:25:25 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"

t_mlximage	get_init_image(t_mlxvars *vars, int w, int h)
{
	t_mlximage	img;

	img.ref = mlx_new_image(vars->mlx, w, h);
	img.size.x = w;
	img.size.y = h;
	img.pixels = mlx_get_data_addr(img.ref, &img.bpp,
			&img.line_size, &img.endian);
	return (img);
}

t_mlximage	get_new_sprite_image(t_mlxvars *vars, char *path)
{
	t_mlximage	img;

	img.ref = mlx_xpm_file_to_image(vars->mlx,
			path, (int *)&img.size.x, (int *)&img.size.y);
	return (img);
}

/**
 * Register image and return index
*/
size_t	register_image(t_mlxvars *vars, t_mlximage img)
{
	size_t	len;

	len = (size_t)ft_lstsize(vars->imgs);
	ft_lstadd_back(&vars->imgs, ft_lstnew(&img));
	return (len);
}

t_mlximage	*get_image_by_key(t_mlxvars *vars, size_t idx)
{
	t_list	*item;

	item = ft_lstget_idx(vars->imgs, idx);
	if (item == NULL)
		return (NULL);
	return (item->content);
}
