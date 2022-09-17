/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:23:06 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/03 15:35:37 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	key_w(t_data *data)
{
	if (data->map[data->yp - 1][data->xp] != '1' && \
		(data->map[data->yp - 1][data->xp] != 'E' || \
		data->score == data->ttl_clc))
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[6], data->xp * 64, data->yp * 64);
		data->yp -= 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[0], data->xp * 64, data->yp * 64);
		if (data->map[data->yp][data->xp] == 'C')
		{
			data->map[data->yp][data->xp] = '0';
			data->score++;
		}
		ft_printf("Step Counter: %d\tScore: %d\n", data->step_cnt++, data->score);
	}
	if (data->map[data->yp][data->xp] == 'E' && data->score == data->ttl_clc)
	{
		ft_printf("Collected Material: %d\n", data->ttl_clc);
		clean_up(data);
	}
}

void	key_s(t_data *data)
{
	if (data->map[data->yp + 1][data->xp] != '1' && \
		(data->map[data->yp + 1][data->xp] != 'E' || \
		data->score == data->ttl_clc))
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[6], data->xp * 64, data->yp * 64);
		data->yp += 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[1], data->xp * 64, data->yp * 64);
		if (data->map[data->yp][data->xp] == 'C')
		{
			data->map[data->yp][data->xp] = '0';
			data->score++;
		}
		ft_printf("Step Counter: %d\tScore: %d\n", data->step_cnt++, data->score);
	}
	if (data->map[data->yp][data->xp] == 'E' && data->score == data->ttl_clc)
	{
		ft_printf("Collected Material: %d\n", data->ttl_clc);
		clean_up(data);
	}
}

void	key_a(t_data *data)
{
	if (data->map[data->yp][data->xp - 1] != '1' && \
		(data->map[data->yp][data->xp - 1] != 'E' || \
		data->score == data->ttl_clc))
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[6], data->xp * 64, data->yp * 64);
		data->xp -= 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[2], data->xp * 64, data->yp * 64);
		if (data->map[data->yp][data->xp] == 'C')
		{
			data->map[data->yp][data->xp] = '0';
			data->score++;
		}
		ft_printf("Step Counter: %d\tScore: %d\n", data->step_cnt++, data->score);
	}
	if (data->map[data->yp][data->xp] == 'E' && data->score == data->ttl_clc)
	{
		ft_printf("Collected Material: %d\n", data->ttl_clc);
		clean_up(data);
	}
}

void	key_d(t_data *data)
{
	if (data->map[data->yp][data->xp + 1] != '1' && \
		(data->map[data->yp][data->xp + 1] != 'E' || \
		data->score == data->ttl_clc))
	{
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[6], data->xp * 64, data->yp * 64);
		data->xp += 1;
		mlx_put_image_to_window(data->mlx, data->win, \
		data->img_path[3], data->xp * 64, data->yp * 64);
		if (data->map[data->yp][data->xp] == 'C')
		{
			data->map[data->yp][data->xp] = '0';
			data->score++;
		}
		ft_printf("Step Counter: %d\tScore: %d\n", data->step_cnt++, data->score);
	}
	if (data->map[data->yp][data->xp] == 'E' && data->score == data->ttl_clc)
	{
		ft_printf("Collected Material: %d\n", data->ttl_clc);
		clean_up(data);
	}
}

void	key_esc(t_data *data)
{
	clean_up(data);
}
