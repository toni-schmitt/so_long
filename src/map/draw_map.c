/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:49:30 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 16:53:37 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	draw_border(t_data *data)
{
	int	x;
	int	y;

	put_image(data, stone_up, data->win_width - TEXTURE_WIDTH, 0);
	x = 0;
	while (x <= data->win_width)
	{
		y = 0;
		while (y <= data->win_height)
		{	
			if (x == 0)
				put_image(data, stone_up, x, y);
			else if (x == data->win_width - TEXTURE_WIDTH)
				put_image(data, stone_down, x, y);
			else if (y == 0)
				put_image(data, stone_up, x, y);
			else if (y == data->win_height - TEXTURE_HEIGHT)
				put_image(data, stone_down, x, y);
			y += TEXTURE_HEIGHT;
		}
		x += TEXTURE_HEIGHT;
	}
}

static void	draw_grass(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map.data[i])
	{
		j = 0;
		while (data->map.data[i][j])
		{
			put_image(data, grass_flower, \
				TEXTURE_WIDTH * j, TEXTURE_HEIGHT * i);
			j++;
		}
		i++;
	}
}

static void	draw_sprites(t_data *data)
{
	int	i;
	int	j;
	int	texture;

	i = 0;
	while (data->map.data[i])
	{
		j = 0;
		while (data->map.data[i][j])
		{
			if (data->map.data[i][j] == 'P')
				texture = statue;
			else if (data->map.data[i][j] == 'C')
				texture = chest;
			else if (data->map.data[i][j] == '0')
				texture = grass_flower;
			else if (data->map.data[i][j] == '1')
				texture = stone_down;
			else if (data->map.data[i][j] == 'E')
				texture = stairs_down;
			put_image(data, texture, TEXTURE_WIDTH * j, TEXTURE_HEIGHT * i);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	draw_grass(data);
	draw_sprites(data);
}
