/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:16:40 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/27 21:06:05 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_correct_vertical_wall(char *data)
{
	if (data[0] != '1')
		return (FALSE);
	if (data[ft_strlen(data) - 1] != '1')
		return (FALSE);
	return (TRUE);
}

static int	is_correct_horizontal_wall(char *data)
{
	while (data && *data)
	{
		if (*data != '1')
			return (FALSE);
		data++;
	}
	return (TRUE);
}

static int	has_correct_chars(char *data)
{
	while (data && *data)
	{
		if (*data < '0')
			return (FALSE);
		if (*data > '1' && *data < 'C')
			return (FALSE);
		if (*data > 'C' && *data < 'E')
			return (FALSE);
		if (*data > 'E' && *data < 'P')
			return (FALSE);
		if (*data > 'P')
			return (FALSE);
		data++;
	}
	return (TRUE);
}

static int	is_valid(char **map_data, int count)
{
	int	i;

	i = 0;
	while (map_data[i])
	{
		if (i == 0 || i == count)
			if (!is_correct_horizontal_wall(map_data[i]))
				return (FALSE);
		if (!is_correct_vertical_wall(map_data[i]))
			return (FALSE);
		if (!has_correct_chars(map_data[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}

void	parse_map(t_map *map)
{
	int		line_count;
	char	*line;
	int		fd;
	int		i;

	i = 0;
	line_count = ft_get_line_count(map->path);
	map->data = malloc(line_count + 1 * sizeof(*map->data));
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
	map->data[i] = NULL;
	if (!is_valid(map->data, line_count))
		ft_puterror("Map is not valid");
}
