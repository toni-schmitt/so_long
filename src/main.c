/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:20:32 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/27 20:16:14 by tschmitt         ###   ########.fr       */
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
			data->images[i].image = mlx_xpm_file_to_image(data->mlx.init, \
			data->images[i].path, &data->images[i].width, \
			&data->images[i].height);
			if (data->images[i].image == NULL)
				ft_puterror("Error creating xpm");
			data->images[i].is_valid = TRUE;
		}
		else
		{
			data->images[i].is_valid = FALSE;
			ft_printf("%s %i is not a valid path.\n", data->images[i].path, i);
		}
		i++;
		close(fd);
	}
}

static void	get_win_propertys(t_map *map, int *width, int *height)
{
	*width = (ft_strlen(ft_getlongeststr(map->data)) + 1) * TEXTURE_WIDTH;
	*height = (ft_get_line_count(map->path) + 1) * TEXTURE_HEIGHT;
}

static int	close_window(void)
{
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
	data->mlx.init = mlx_init();	ft_printf("Init mlx\n");
	if (data->mlx.init == NULL)
		return (ft_puterror("Error initializing minilibx"));
	init_texture_paths(data);	ft_printf("Init text paths\n");
	create_images(data);		ft_printf("Creating images\n");
	data->map.path = argv[1];
	parse_map(&data->map);		ft_printf("Parsing map\n");
	get_win_propertys(&data->map, &data->win_width, &data->win_height);	ft_printf("Getting win props\n");
	printf("mlx: %p\nwin: %p\nwinh: %i winw: %i\n", data->mlx.init, data->mlx.win, data->win_height, data->win_width);
	data->mlx.win = mlx_new_window(data->mlx.init, data->win_width, \
		data->win_height, "SO LONG");	printf("mlx: %p\nwin: %p\nwinh: %i winw: %i\n", data->mlx.init, data->mlx.win, data->win_height, data->win_width);ft_printf("Creating mlx window\n");
	if (data->mlx.win == NULL)
		return (ft_puterror("Error creating window"));
	draw_map(data);				ft_printf("Drawing map\n");
	mlx_hook(data->mlx.win, 17, 1L << 17, close_window, data);
	// mlx_loop_hook(data->mlx.init, close_window, data);
	// mlx_do_sync(data->mlx.init);
	ft_printf("Stating loop\n");
	mlx_loop(data->mlx.init);
	ft_printf("Stopping loop\n");
	free(data);
	close_window();
	return (EXIT_SUCCESS);
}
