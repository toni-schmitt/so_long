/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 17:16:40 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/27 17:46:25 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_valid(char **map_data, int count)
{
	int	i;
	int	j;

	i = 0;
	while (map_data[i])
	{
		j = 0;
		if (!ft_strhas(map_data[i], "01CEP"))
			return (FALSE);
		if (map_data[i][0] != '1'
			|| map_data[i][ft_strlen(map_data[i]) - 1] != '1')
			return (FALSE);
		while (map_data[i][j])
		{
			if (i == 0 || i == count - 1)
				if (map_data[i][j] != '1')
					return (FALSE);
			j++;
		}
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
