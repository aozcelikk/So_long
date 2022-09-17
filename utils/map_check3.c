/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:23:04 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/02 12:44:52 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	left_vertical_check(t_data *data)
{
	while (data->map[data->wall_chk_arg])
	{
		if (data->map[data->wall_chk_arg][0] != '1')
		{
			ft_printf("Error\nLeft Wall Wrong!!\n");
			exit(1);
		}
		data->wall_chk_arg++;
	}
}

static void	top_horizontal_check(t_data *data)
{
	while (data->map[0][data->wall_chk_idx])
	{
		if (data->map[0][data->wall_chk_idx] != '1')
		{
			ft_printf("Error\nUpper Wall Wrong!!\n");
			exit(1);
		}
		data->wall_chk_idx++;
	}
}

void	map_wall_check(t_data *data)
{
	left_vertical_check(data);
	top_horizontal_check(data);
	data->wall_chk_arg -= 1;
	data->wall_chk_idx = 0;
	while (data->map[data->wall_chk_arg][data->wall_chk_idx])
	{
		if (data->map[data->wall_chk_arg] \
			[data->wall_chk_idx] != '1')
		{
			ft_printf("Error\nLower Wall Wrong!!\n");
			exit(1);
		}
		data->wall_chk_idx++;
	}
	data->wall_chk_idx -= 1;
	while (data->wall_chk_arg > 0)
	{
		if (data->map[data->wall_chk_arg] \
			[data->wall_chk_idx] != '1')
		{
			ft_printf("Error\nRight Wall Wrong!!\n");
			exit(1);
		}
		data->wall_chk_arg--;
	}
}
