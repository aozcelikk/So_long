/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:23:09 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/02 13:51:41 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	find_key(int keycode, void *data)
{
	if (keycode == 13)
		key_w(data);
	else if (keycode == 1)
		key_s(data);
	else if (keycode == 2)
		key_d(data);
	else if (keycode == 0)
		key_a(data);
	else if (keycode == 53)
		key_esc(data);
	return (keycode);
}

void	set_zero(t_data *data)
{
	data->score = 0;
	data->ttl_clc = 0;
	data->step_cnt = 1;
	data->new_cnt = 1;
	data->img_idx = 0;
	data->img_arg = 0;
	data->c_cnt = 0;
	data->e_cnt = 0;
	data->p_cnt = 0;
	data->ltr_arg = 0;
	data->ltr_idx = 0;
	data->wall_chk_idx = 0;
	data->wall_chk_arg = 0;
}

int	clean_up(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data->img_path);
	ft_printf("!Game OVER!\n");
	exit (0);
}
