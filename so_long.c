/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:41:35 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/03 18:33:00 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_imgs(void)
{
	int	fd;

	fd = open("./xpm/W.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/S.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/A.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/D.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/C.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/B.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/M.xpm", O_RDONLY) == -1;
	fd |= open("./xpm/E.xpm", O_RDONLY) == -1;
	return (fd);
}

int	main(int arg, char **av)
{
	t_data	data;
	int		wth;

	if (arg == 2 && check_mapname(av[1]) && !check_imgs())
	{
		set_zero(&data);
		map_read(&data, av[1]);
		map_rectangle_check(&data);
		map_ltr_check(&data);
		map_wall_check(&data);
		map_newline_check(&data);
		map_all_check(&data);
		wth = data.row_len * 64;
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, wth, data.row_cnt * 64, "SOLONG");
		images_create(&data);
		map_put_image(&data);
		mlx_hook(data.win, 2, 1L << 0, find_key, &data);
		mlx_hook(data.win, 17, 0, clean_up, &data);
		mlx_loop(data.mlx);
	}
	else
		ft_printf("Error\nMissing argument, picture or Incorrect extension!!\n");
	exit(1);
}
