/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:23:02 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/02 12:46:24 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_rectangle_check(t_data *data)
{
	int	arg;

	arg = 1;
	while (data->map[arg])
	{
		if (row_cnt(data->map[0]) != row_cnt(data->map[arg]))
		{
			ft_printf("Error\nMap Is Not Rectangular!!\n");
			exit(1);
		}
		arg++;
	}
}

void	map_newline_check(t_data *data)
{
	if (data->row_cnt != data->new_cnt)
	{
		ft_printf("Error\nMap Not Closed!!\n");
		exit(1);
	}
}

void	map_all_check(t_data *data)
{
	int	arg;
	int	idx;

	arg = 1;
	idx = 1;
	while (arg < data->row_cnt)
	{
		idx = 1;
		while (data->map[arg][idx])
		{
			if (data->map[arg][idx] == '0' || data->map[arg][idx] == 'P' || \
				data->map[arg][idx] == '1' || data->map[arg][idx] == 'C' || \
				data->map[arg][idx] == 'E')
					idx++;
			else
			{
				ft_printf("Error\nUndefined CHARACTER!!\n");
				ft_printf("Arg: %d\nIdx: %d\n", arg, idx);
				exit(1);
			}
		}
		arg++;
	}
}

int	row_cnt(char *row)
{
	int	i;

	i = 0;
	while (row[i])
		i++;
	return (i);
}

void	map_ltr_check(t_data *data)
{
	while (data->map[data->ltr_arg])
	{
		data->ltr_idx = 0;
		while (data->map[data->ltr_arg][data->ltr_idx])
		{
			if (data->map[data->ltr_arg] \
				[data->ltr_idx] == 'P')
			data->p_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'E')
			data->e_cnt++;
			else if (data->map[data->ltr_arg] \
					[data->ltr_idx] == 'C')
			data->c_cnt++;
			data->ltr_idx++;
		}
		data->ltr_arg++;
	}
	if (data->p_cnt == 0 || data->p_cnt > 1 || \
		data->e_cnt == 0 || data->c_cnt == 0)
	{
		ft_printf("Error\nPlayer, Material, or Exit Wrong!!\n");
		exit(1);
	}
}
