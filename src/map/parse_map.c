/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:16:40 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/04 19:19:57 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_pos_index(char c)
{
	if (c == 'P')
		return (player);
	if (c == 'E')
		return (map_exit);
	if (c == 'C')
		return (collectible);
	if (c == '1')
		return (wall);
	return (-1);
}

static void	save_positions(t_map *map)
{
	int	i;
	int	j;
	int	pos_index;

	i = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			pos_index = get_pos_index(map->data[i][j]);
			if (pos_index == -1)
			{
				j++;
				continue ;
			}
			map->positions[pos_index][map->pos_count[pos_index]].x \
			= TEXTURE_WIDTH * j;
			map->positions[pos_index][map->pos_count[pos_index]].y \
			= i * TEXTURE_HEIGHT;
			map->pos_count[pos_index]++;
			j++;
		}
		i++;
	}
}

static void	interpret_map(t_map *map)
{
	validate_map(map->data, map->line_count);
	init_positions(map);
	save_positions(map);
}

void	parse_map(t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	map->line_count = ft_get_line_count(map->path);
	map->data = ft_calloc((map->line_count + 1), \
		sizeof(*map->data));
	if (map->data == NULL)
		ft_puterror("Error allocating map data");
	fd = open(map->path, O_RDONLY);
	if (fd < 0)
		ft_puterror("Error opening map");
	line = get_next_line(fd);
	while (line)
	{
		map->data[i] = ft_strndup(line, ft_strlen(line) - 1);
		if (map->data[i] == NULL)
			ft_puterror("Error allocating line of map data");
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	interpret_map(map);
}
