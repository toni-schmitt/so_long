/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:11:41 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 16:44:15 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_walls(char **data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] == '1')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	count_collectibles(char **data)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (data[i])
	{
		j = 0;
		while (data[i][j])
		{
			if (data[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	init_positions(t_map *map)
{
	map->collected = 0;
	map->movement_counter = 0;
	map->positions[player] = ft_calloc(2, sizeof(*map->positions[player]));
	if (map->positions[player] == NULL)
		ft_puterror("Error allocating map positions");
	map->positions[map_exit] = ft_calloc(2, \
		sizeof(*map->positions[map_exit]));
	if (map->positions[map_exit] == NULL)
		ft_puterror("Error allocating map positions");
	map->positions[collectible] = ft_calloc(\
	count_collectibles(map->data) + 1, \
	sizeof(*map->positions[collectible]));
	if (map->positions[collectible] == NULL)
		ft_puterror("Error allocating map positions");
	map->positions[wall] = ft_calloc(count_walls(map->data) + 1, \
		sizeof(*map->positions[wall]));
	if (map->positions[wall] == NULL)
		ft_puterror("Error allocating map positions");
	map->pos_count[player] = 0;
	map->pos_count[map_exit] = 0;
	map->pos_count[collectible] = 0;
	map->pos_count[wall] = 0;
}
