/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: warredevriese <marvin@42.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:15:57 by warredevriese     #+#    #+#             */
/*   Updated: 2023/05/15 12:41:41 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
    t_iso       **data_array;
    t_dimensions    map;
    t_fdf_params fdf;

    (void)argc;
	//add error handling
    get_data(argv[1], &data_array, &map);
    apply_scaling(&data_array, map);
	fdf.mlx_params = init_mlx_params(&fdf);
	draw_to_image(data_array, map, &fdf.mlx_params);
	mlx_put_image_to_window(fdf.mlx_params.mlx, fdf.mlx_params.win, fdf.mlx_params.img, 0, 0);
	handle_hooks(data_array, map, fdf.mlx_params);
    mlx_loop(fdf.mlx_params.mlx);
    return (0);
}
