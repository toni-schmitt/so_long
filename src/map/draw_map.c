/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:49:30 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/07 16:34:54 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
