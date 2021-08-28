/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:20:32 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/28 16:51:48 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	new_sprite(void *mlx, t_image *image)
{
	image->image = mlx_xpm_file_to_image(mlx, image->path, \
	&image->size.x, &image->size.y);
	image->pixels = mlx_get_data_addr(image->image, &image->bpp, \
	&image->line_size, &image->endian);
}

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
	// *width = 1000;
	// *height = 1000;
	// return ;
	*width = (ft_strlen(map->data[0]) + 1) * TEXTURE_WIDTH;
	*height = (ft_get_line_count(map->path) + 1) * TEXTURE_HEIGHT;
}

static int	close_window(t_data *data)
{
	free(data);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	if (argc != 2)
		return (ft_puterror("Usage: ./so_long [map_path]"));
	data = malloc(sizeof(*data));
	if (data == NULL)
		return (ft_puterror("Error allocating data struct"));
	ft_printf("mlx_init\n");
	data->mlx.init = mlx_init();
	if (data->mlx.init == NULL)
		return (ft_puterror("Error initializing minilibx"));
	ft_printf("mlx initialized...\n");
	ft_printf("Initializing texture paths...\n");
	init_texture_paths(data);
	ft_printf("Initialized texture paths...\n");
	ft_printf("Creating images...\n");
	create_images(data);
	ft_printf("Images created...\n");
	data->map.path = argv[1];
	ft_printf("Parsing map...\n");
	parse_map(&data->map);
	ft_printf("Map parsed...\n");
	get_win_propertys(&data->map, &data->win_width, &data->win_height);
	ft_printf("Creating window...\n");
	data->mlx.win = mlx_new_window(data->mlx.init, data->win_width, \
		data->win_height, "SO LONG");
	ft_printf("Window created...\n");
	if (data->mlx.win == NULL)
		return (ft_puterror("Error creating window"));
	ft_printf("Drawing map...\n");
	draw_map(data);
	ft_printf("Map drawed...\n");
	ft_printf("Starting hook...\n");
	mlx_hook(data->mlx.win, 17, 1L << 17, close_window, data);
	ft_printf("Starting loop...\n");
	mlx_loop(data->mlx.init);
	ft_printf("After loop\n");
	close_window(data);
	return (EXIT_SUCCESS);
}
