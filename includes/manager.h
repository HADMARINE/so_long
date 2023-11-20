/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:57:44 by lhojoon           #+#    #+#             */
/*   Updated: 2023/11/20 16:24:40 by lhojoon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGER_H
# define MANAGER_H

# include "so_long.h"

t_mlxvars	init_mlxvars(void);
BOOL		free_mlx(t_mlxvars *p);
BOOL		mlx_pipeline(t_mlxvars *vars);

#endif