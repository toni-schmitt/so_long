/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:11:41 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 19:10:33 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_chars(char **data, char ch)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (data[i])
	{
		count += ft_chrcount(data[i], ch);
		i++;
	}
	return (count);
}

void	init_positions(t_map *map)
{
	map->positions[player] = ft_calloc(count_chars(map->data, 'P'), \
		sizeof(*map->positions[player]));
	if (map->positions[player] == NULL)
		ft_puterror("Error allocating map positions");
	map->positions[map_exit] = ft_calloc(count_chars(map->data, 'E'), \
		sizeof(*map->positions[map_exit]));
	if (map->positions[map_exit] == NULL)
		ft_puterror("Error allocating map positions");
	map->positions[collectible] = ft_calloc(count_chars(map->data, 'C') + 1, \
		sizeof(*map->positions[collectible]));
	if (map->positions[collectible] == NULL)
		ft_puterror("Error allocating map positions");
	map->positions[wall] = ft_calloc(count_chars(map->data, '1') + 1, \
		sizeof(*map->positions[wall]));
	if (map->positions[wall] == NULL)
		ft_puterror("Error allocating map positions");
	map->pos_count[player] = 0;
	map->pos_count[map_exit] = 0;
	map->pos_count[collectible] = 0;
	map->pos_count[wall] = 0;
	map->collected = 0;
	map->movement_counter = 0;
}
