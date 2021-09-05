/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 17:06:35 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 19:01:00 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	update_collectible(t_map *map, int x_plus, int y_plus)
{
	int	i;

	i = 0;
	while (i < map->pos_count[collectible])
	{
		if (map->positions[collectible][i].x == \
			map->positions[player]->x + x_plus &&
			map->positions[collectible][i].y == \
			map->positions[player]->y + y_plus)
		{
			map->positions[collectible][i].x = FALSE;
			map->positions[collectible][i].y = FALSE;
			map->collected++;
		}
		i++;
	}
}

static int	is_movable_space(t_data *data, int x_plus, int y_plus)
{
	int	j;

	if (data->map.positions[player]->x + x_plus > data->win_width || \
		data->map.positions[player]->y + y_plus > data->win_height || \
		data->map.positions[player]->x + x_plus < 0 || \
		data->map.positions[player]->y + y_plus < 0)
		return (FALSE);
	j = 0;
	while (j < data->map.pos_count[wall])
	{
		if (data->map.positions[player]->x + x_plus == \
			data->map.positions[wall][j].x &&
			data->map.positions[player]->y + y_plus == \
			data->map.positions[wall][j].y)
			return (FALSE);
		j++;
	}
	return (TRUE);
}

static int	is_moving_to_exit(t_data *data, int x_plus, int y_plus)
{
	int	i;

	i = 0;
	while (i < data->map.pos_count[map_exit])
	{
		if (data->map.positions[player]->x + x_plus == \
			data->map.positions[map_exit][i].x && \
			data->map.positions[player]->y + y_plus == \
			data->map.positions[map_exit][i].y)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static int	was_on_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map.pos_count[map_exit])
	{
		if (data->map.positions[player]->x == \
			data->map.positions[map_exit][i].x && \
			data->map.positions[player]->y == \
			data->map.positions[map_exit][i].y)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

int	move_player(t_data *data, int x_plus, int y_plus)
{
	int	image;

	x_plus *= TEXTURE_WIDTH;
	y_plus *= TEXTURE_HEIGHT;
	image = grass_flower;
	if (!is_movable_space(data, x_plus, y_plus))
		return (-1);
	if (is_moving_to_exit(data, x_plus, y_plus))
		if (data->map.pos_count[collectible] == data->map.collected)
			return (win_game(data));
	if (was_on_exit(data))
		image = stairs_down;
	update_collectible(&data->map, x_plus, y_plus);
	put_image(data, image, data->map.positions[player]->x, \
	data->map.positions[player]->y);
	put_image(data, statue, data->map.positions[player]->x + x_plus, \
	data->map.positions[player]->y + y_plus);
	ft_printf("%i\n", ++data->map.movement_counter);
	data->map.positions[player]->x += x_plus;
	data->map.positions[player]->y += y_plus;
	return (1);
}
