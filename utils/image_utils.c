/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:22:56 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/03 17:54:52 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdio.h>

void	images_create(t_data *data)
{
	int	x;
	int	y;

	data->img_path = ft_calloc(8, sizeof(void *));
	if (!data->img_path)
	{
		free(data->img_path);
		exit(0);
	}
	data->img_path[0] = mlx_xpm_file_to_image(data->mlx, "./xpm/W.xpm", &x, &y);
	data->img_path[1] = mlx_xpm_file_to_image(data->mlx, "./xpm/S.xpm", &x, &y);
	data->img_path[2] = mlx_xpm_file_to_image(data->mlx, "./xpm/A.xpm", &x, &y);
	data->img_path[3] = mlx_xpm_file_to_image(data->mlx, "./xpm/D.xpm", &x, &y);
	data->img_path[4] = mlx_xpm_file_to_image(data->mlx, "./xpm/C.xpm", &x, &y);
	data->img_path[5] = mlx_xpm_file_to_image(data->mlx, "./xpm/B.xpm", &x, &y);
	data->img_path[6] = mlx_xpm_file_to_image(data->mlx, "./xpm/M.xpm", &x, &y);
	data->img_path[7] = mlx_xpm_file_to_image(data->mlx, "./xpm/E.xpm", &x, &y);
}

static void	map_put_img_for_zero(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, \
	data->img_path[6], data->img_idx * 64, data->img_arg * 64);
}

static void	map_put_img_for_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, \
	data->img_path[1], data->img_idx * 64, data->img_arg * 64);
	data->xp = data->img_idx;
	data->yp = data->img_arg;
}

void	map_put_image(t_data *data)
{
	while (data->map[data->img_arg])
	{
		data->img_idx = 0;
		while (data->map[data->img_arg][data->img_idx])
		{
			if (data->map[data->img_arg][data->img_idx] == '0')
				map_put_img_for_zero(data);
			else if (data->map[data->img_arg][data->img_idx] == '1')
				mlx_put_image_to_window(data->mlx, data->win, \
				data->img_path[5], data->img_idx * 64, data->img_arg * 64);
			else if (data->map[data->img_arg][data->img_idx] == 'P')
				map_put_img_for_player(data);
			else if (data->map[data->img_arg][data->img_idx] == 'C')
			{
				mlx_put_image_to_window(data->mlx, data->win, \
				data->img_path[4], data->img_idx * 64, data->img_arg * 64);
				data->ttl_clc++;
			}
			else if (data->map[data->img_arg][data->img_idx] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, \
				data->img_path[7], data->img_idx * 64, data->img_arg * 64);
			data->img_idx++;
		}
		data->img_arg++;
	}
}
