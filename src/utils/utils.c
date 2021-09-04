/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:39:21 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/04 18:49:04 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

static int	count_collectibles(char **data)
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
