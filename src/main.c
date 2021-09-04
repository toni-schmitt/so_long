/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:20:32 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/04 16:54:25 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_images(t_data *data)
{
	int	i;
	int	fd;

	i = 0;
	while (i < NO_OF_TEXTURES)
	{
		fd = open(data->images[i].path, O_RDONLY);
		if (fd >= 0)
		{
			new_sprite(data->mlx.init, &data->images[i]);
			if (data->images[i].image == NULL)
				ft_puterror("Error creating xpm");
			data->images[i].is_valid = TRUE;
		}
		else
		{
			data->images[i].is_valid = FALSE;
			ft_printf("%s is not a valid path.\n", data->images[i].path);
		}
		i++;
		close(fd);
	}
}

static void	get_win_propertys(t_map *map, int *width, int *height)
{
	*width = ft_strlen(map->data[0]) * TEXTURE_WIDTH;
	*height = ft_get_line_count(map->path) * TEXTURE_HEIGHT;
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		return (ft_puterror("Usage: ./so_long [map_path]"));
	data = malloc(sizeof(*data));
	if (data == NULL)
		return (ft_puterror("Error allocating data struct"));
	data->map.path = argv[1];
	parse_map(&data->map);
	get_win_propertys(&data->map, &data->win_width, &data->win_height);
	data->mlx.init = mlx_init();
	if (data->mlx.init == NULL)
		return (ft_puterror("Error initializing minilibx"));
	init_texture_paths(data);
	create_images(data);
	data->mlx.win = mlx_new_window(data->mlx.init, data->win_width, \
		data->win_height, "SO LONG");
	if (data->mlx.win == NULL)
		return (ft_puterror("Error creating window"));
	draw_map(data);
	mlx_hook(data->mlx.win, 17, 1L << 17, close_window, data);
	mlx_key_hook(data->mlx.win, handle_keys, data);
	mlx_loop(data->mlx.init);
	close_window(data);
	return (EXIT_SUCCESS);
}
