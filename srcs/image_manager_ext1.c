/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manager_ext1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 17:01:31 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/25 17:17:41 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// t_mlximage	*get_init_image_ptr(void)
// {
// 	t_mlximage	*img;

// 	img = (t_mlximage *)malloc(sizeof(t_mlximage));
// 	if (!img)
// 		return (NULL);
// 	img->ref = NULL;
// 	img->size.x = 0;
// 	img->size.y = 0;
// 	img->pixels = NULL;
// 	img->bpp = 0;
// 	img->endian = 0;
// 	img->endian = 0;
// 	return (img);
// }

// t_mlximage	*get_init_image_ptr_value(t_mlxvars *vars, int w, int h)
// {
// 	t_mlximage	*img;

// 	img = (t_mlximage *)malloc(sizeof(t_mlximage));
// 	if (!img)
// 		return (NULL);
// 	img->ref = mlx_new_image(vars->mlx, w, h);
// 	img->size.x = w;
// 	img->size.y = h;
// 	img->pixels = mlx_get_data_addr(img->ref, &img->bpp,
// 			&img->line_size, &img->endian);
// 	return (img);
// }

t_mlximage	*get_new_sprite_image_ptr(t_mlxvars *vars, char *path)
{
	t_mlximage	*img;
	int			x;
	int			y;

	img = mlx_xpm_file_to_image(vars->mlx,
			path, &x, &y);
	if (!img)
		return (NULL);
	img->width = x;
	img->height = y;
	return (img);
}

/**
 * Register image
*/
bool	register_image(t_mlxvars *vars, t_mlximage *img)
{
	if (!img)
		return (false);
	ft_lstadd_back(&vars->imgs, ft_lstnew(img));
	return (true);
}

t_mlximage	*get_image_by_key(t_mlxvars *vars, t_sl_img_keys idx)
{
	t_list	*item;

	item = ft_lstget_idx(vars->imgs, (size_t)idx);
	if (item == NULL)
		return (NULL);
	return (item->content);
}
