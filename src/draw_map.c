/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 18:49:30 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/27 17:52:29 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_image(t_data *data, int image, int x, int y)
{
	if (!data->images[image].is_valid)
		return ;
	if (x > data->win_width - TEXTURE_WIDTH || y > data->win_height - TEXTURE_HEIGHT)
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, \
		data->images[image].image, x, y);
}

static void	draw_border(t_data *data)
{
	int	x;
	int	y;

	put_image(data, stone_up, 0, 0);
	put_image(data, stone_up, data->win_width - TEXTURE_WIDTH, 0);
	put_image(data, stone_down, 0, data->win_height - TEXTURE_HEIGHT);
	put_image(data, stone_down, data->win_width - TEXTURE_WIDTH, \
		data->win_height - TEXTURE_WIDTH);
	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			if (y != 0 && y != data->win_height - TEXTURE_HEIGHT)
			{
				if (x == 0)
					put_image(data, stone_up, x, y);
				else if (x == data->win_width - TEXTURE_WIDTH)
					put_image(data, stone_up, x, y);
			}
			if (y == 0)
				put_image(data, stone_up, x, y);
			else if (y == data->win_height - TEXTURE_HEIGHT \
				&& (x != 0 || x != data->win_width - TEXTURE_WIDTH))
				put_image(data, stone_down, x, y);
			y += TEXTURE_HEIGHT;
		}
		x += TEXTURE_HEIGHT;
	}
}

void	draw_map(t_data *data)
{
	draw_border(data);
}
