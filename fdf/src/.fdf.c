/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   .fdf.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:48:11 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/10 14:19:07 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void free_data_array(t_iso ***data_array, size_t height) 
{
    size_t i;

	i = 0;
    while (i < height)
        free((*data_array)[i++]);
    free(*data_array);
	write(1, "Data successfully freed", 23);
}

int keypress_hook(int keycode, t_mlx_params *params)
{
    if (keycode == 53)
    {
        free_data_array(&(params->data_array), params->map.height);
        mlx_destroy_window(params->mlx, params->win);
        exit(0);
    }
    return (0);
}

int destroy_hook(t_mlx_params *params)
{
    free_data_array(&(params->data_array), params->map.height);
    mlx_destroy_window(params->mlx, params->win);
    exit(0);
    return (0);
}

int		main(int argc, char **argv)
{
	t_iso		**data_array;
	t_dimensions	map;
	t_mlx_params fdf;

	(void)argc;
	get_data(argv[1], &data_array, &map);
	apply_scaling(&data_array, map); 
	fdf.mlx = mlx_init();
	fdf.win = mlx_new_window(fdf.mlx, 1920, 1920, "Fil de Fer");
	fdf.img = mlx_new_image(fdf.mlx, 1920, 1920);
	mlx_hook(fdf.win, 2, 1L<<0, keypress_hook, &fdf);
	mlx_hook(fdf.win, 17, 0, destroy_hook, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
