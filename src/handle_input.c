/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:56:42 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 16:53:04 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

enum
{
	up = 0,
	down = 1,
	left = 2,
	right = 3
};

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
	if (data->map.positions[player]->x + x_plus == \
		data->map.positions[map_exit]->x && \
		data->map.positions[player]->y + y_plus == \
		data->map.positions[map_exit]->y)
		return (TRUE);
	return (FALSE);
}

static int	move(t_data *data, int x_plus, int y_plus)
{
	x_plus *= TEXTURE_WIDTH;
	y_plus *= TEXTURE_HEIGHT;
	if (!is_movable_space(data, x_plus, y_plus))
		return (-1);
	if (is_moving_to_exit(data, x_plus, y_plus))
		return (win_game(data));
	update_collectible(&data->map, x_plus, y_plus);
	put_image(data, grass_flower, data->map.positions[player]->x, \
	data->map.positions[player]->y);
	put_image(data, statue, data->map.positions[player]->x + x_plus, \
	data->map.positions[player]->y + y_plus);
	ft_printf("%i\n", ++data->map.movement_counter);
	data->map.positions[player]->x += x_plus;
	data->map.positions[player]->y += y_plus;
	return (1);
}

int	handle_keys(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		return (close_window(data));
	if (key == KEY_W)
		return (move(data, 0, -1));
	if (key == KEY_S)
		return (move(data, 0, +1));
	if (key == KEY_A)
		return (move(data, -1, 0));
	if (key == KEY_D)
		return (move(data, +1, 0));
	return (-1);
}
