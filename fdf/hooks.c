/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 15:00:00 by wdevries          #+#    #+#             */
/*   Updated: 2023/05/17 16:52:12 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void free_data_array(t_iso ***data_array, size_t height)
{
    size_t i;

	if (*data_array == NULL)
		return ;
    i = 0;
    while (i < height)
		free((*data_array)[i++]);
    free(*data_array);
	*data_array = NULL;
    write(1 , "Data successfully freed", 23);
}

static int keypress_hook(int keycode, void *param)
{
    if (keycode == 65307)
			mlx_destroy_window(params->mlx_params.mlx, params->mlx_params.win);
    return (0);
}

static int destroy_hook(t_fdf_params *params)
{
    free_data_array(&(params->data_array), params->map.rows);
    if (params->mlx_params.win != NULL) 
	{
		mlx_destroy_window(params->mlx_params.mlx, params->mlx_params.win);
		params->mlx_params.win = NULL;
	}
	exit(0);
    return (0);
}

void	handle_hooks(t_iso **data_array, t_dimensions map, t_mlx_params mlx_params)
{
	t_fdf_params	fdf;

	fdf.data_array = data_array;
    fdf.map = map;
	fdf.mlx_params = mlx_params;
    mlx_hook(fdf.mlx_params.win, 2, 1L<<0, keypress_hook, &fdf);
    mlx_hook(fdf.mlx_params.win, 17, 0, destroy_hook, &fdf);
}
