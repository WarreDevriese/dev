/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdevries <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:11:36 by wdevries          #+#    #+#             */
/*   Updated: 2023/04/29 15:54:18 by wdevries         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	get_frame_dimensions(t_map dimensions, int **data)
{
	t_iso	frame;

	frame.height = (((dimensions.width - (size_t)(**data)[height][width] * cos(30))) - (0 - (size_t)(**data)[0][0]) * cos(30));
	frame.width = (0 + (dimensions.width + (size_t)(**data)[0][width]))(dimensions.height + (0 + (size_t)(**data)[0][dimensions.height]));
	frame.ratio = frame.height / frame.width;
}
