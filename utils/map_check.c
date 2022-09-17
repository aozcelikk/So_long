/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aozcelik <aozcelik@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:22:58 by aozcelik          #+#    #+#             */
/*   Updated: 2022/06/02 12:47:39 by aozcelik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	check_mapname(char *map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	if (*map == 0 || i-- < 5)
		return (0);
	if (map[i] == 'r' && map[i - 1] == 'e' && map[i - 2] == 'b' && \
		map[i - 3] == '.')
		return (1);
	else
		return (0);
}

int	map_len(char *av)
{
	int		fd;
	int		i;
	int		m_cnt;
	char	s;

	m_cnt = 0;
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (0);
	i = read(fd, &s, 1);
	while (i > 0)
	{
		i = read(fd, &s, 1);
		m_cnt++;
	}
	close(fd);
	if (m_cnt == 0)
	{
		ft_printf("Error\nCould not read file!!\n");
		exit(0);
	}
	return (m_cnt);
}

void	map_read(t_data *data, char *av)
{
	char	*map_s;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nMap Not Found!!\n");
		exit(1);
	}
	map_s = get_map(fd, av);
	data->map = ft_split(map_s, '\n', data);
	free(map_s);
}

char	*get_map(int fd, char *av)
{
	char	*map_s;
	int		bufsize;

	bufsize = map_len(av);
	map_s = (char *)ft_calloc(bufsize + 1, sizeof(char));
	if (!map_s)
		return (0);
	read(fd, map_s, bufsize);
	map_s[bufsize] = 0;
	if (!*map_s)
		return (get_map_free(map_s));
	return (map_s);
}

void	*get_map_free(void *f)
{
	free (f);
	return (NULL);
}
