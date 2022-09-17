/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:22:42 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/03 18:33:12 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./library/minilibx_opengl/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdarg.h>

typedef struct s_long
{
	void	*mlx;
	void	*win;
	void	**img_path;
	char	**map;
	int		score;
	int		row_len;
	int		row_c;
	int		row_cnt;
	int		new_cnt;
	int		img_idx;
	int		img_arg;
	int		map_x;
	int		map_y;
	int		xp;
	int		yp;
	int		ltr_idx;
	int		ltr_arg;
	int		p_cnt;
	int		c_cnt;
	int		e_cnt;
	int		wal_c_up;
	int		wal_c_dn;
	int		wal_c_rt;
	int		wal_c_lt;
	int		wall_chk_arg;
	int		wall_chk_idx;
	int		step_cnt;
	int		ttl_clc;
}	t_data;

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	*get_map_free(void *f);
void	set_zero(t_data *data);
void	map_rectangle_check(t_data *data);
void	map_newline_check(t_data *data);
void	map_all_check(t_data *data);
void	map_ltr_check(t_data *data);
void	map_wall_check(t_data *data);
void	images_create(t_data *data);
void	map_put_image(t_data *data);
void	map_read(t_data *data, char *av);
void	key_w(t_data *data);
void	key_s(t_data *data);
void	key_a(t_data *data);
void	key_d(t_data *data);
void	key_esc(t_data *data);
char	*get_map(int fd, char *av);
char	**ft_split(char const *s, char c, t_data *data);
int		check_imgs(void);
int		check_mapname(char *map);
int		ft_printf(const	char *s, ...);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putchar(char c);
int		read_map(char *av);
int		map_len(char *av);
int		row_cnt(char *row);
int		clean_up(t_data *data);
int		find_key(int keycode, void *data);

#endif