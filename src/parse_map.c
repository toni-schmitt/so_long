/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:16:40 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/04 15:23:19 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	save_positions(t_map *map, char *line, int i)
{
	int	j;

	j = 0;
	while (line && line[j])
	{
		if (line[j] == 'P')
		{
			map->pos[player].x = j * TEXTURE_WIDTH;
			map->pos[player].y = i * TEXTURE_HEIGHT;
		}
		if (line[j] == 'E')
		{
			map->pos[map_exit].x = j * TEXTURE_WIDTH;
			map->pos[map_exit].y = i * TEXTURE_HEIGHT;
		}
		j++;
	}
}

void	parse_map(t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	i = 0;
	map->data = ft_calloc((ft_get_line_count(map->path) + 1), \
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
		save_positions(map, map->data[i], i);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	validate_map(map->data, ft_get_line_count(map->path));
}
