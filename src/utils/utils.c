/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:39:21 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 16:54:01 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	win_game(t_data *data)
{
	ft_printf("Congrats you won the level!!\n");
	ft_printf("Stats:\n");
	ft_printf("Moves:\t\t%i\n", data->map.movement_counter);
	ft_printf("Collected:\t%i\n", data->map.collected);
	ft_printf("Available:\t%i\n", data->map.pos_count[collectible]);
	return (close_window(data));
}

int	close_window(t_data *data)
{
	free_data(data, EXIT_SUCCESS);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

void	new_sprite(void *mlx, t_image *image)
{
	image->image = mlx_xpm_file_to_image(mlx, image->path, \
	&image->size.x, &image->size.y);
	image->pixels = mlx_get_data_addr(image->image, &image->bpp, \
	&image->line_size, &image->endian);
}

void	put_image(t_data *data, int image, unsigned int x, unsigned int y)
{
	if (image >= NO_OF_TEXTURES || !data->images[image].is_valid)
		return ;
	if (x > data->win_width - TEXTURE_WIDTH \
	|| y > data->win_height - TEXTURE_HEIGHT)
		return ;
	mlx_put_image_to_window(data->mlx.init, data->mlx.win, \
		data->images[image].image, x, y);
}

void	init_texture_paths(t_data *data)
{
	data->images[grass_flower].path = "./textures/floor/grass_flower.xpm";
	data->images[chest].path = "./textures/sprites/chest.xpm";
	data->images[statue].path = "./textures/sprites/statue.xpm";
	data->images[stone_down].path = "./textures/wall/stone_down.xpm";
	data->images[stone_up].path = "./textures/wall/stone_up.xpm";
	data->images[stairs_down].path = "./textures/sprites/stairs_down.xpm";
}
