/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 09:23:31 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/15 13:39:37 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx_params init_mlx_params(t_fdf_params *fdf)
{
    t_mlx_params    params;

    params->mlx = mlx_init();
    params->win = mlx_new_window(params->mlx, 1920, 1920, "Fil de Fer");
    params->img = mlx_new_image(params->mlx, 1920, 1920);
    params->addr = mlx_get_data_addr(params->img, &params->bits_per_pixel, &params->line_length, &params->endian);
    return (params);
}

void	draw_to_image(t_iso **data_array, t_dimensions map, t_mlx_params *params)
{
	
}
