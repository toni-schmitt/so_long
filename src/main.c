/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:20:32 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/26 17:54:08 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_data *data)
{
	data->image[0].image = mlx_xpm_file_to_image(data->mlx.init, "/Users/tschmitt/proj/so_long/dungeon_sheet.xpm", &data->image[0].width, &data->image[0].height);
	if (data->image[0].image == NULL)
		ft_puterror("Error reading image");
}

void	get_win_propertys(t_map *map, int *width, int *height)
{
	*width = ft_strlen(ft_getlongeststr(map->data)) * 40;
	*height = ft_get_line_count(map->path) * 40;
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		return (ft_puterror("Usage: ./so_long [map_path]"));
	data.mlx.init = mlx_init();
	create_images(&data);
	ft_printf("1 %p\n", data.image[0].image);
	data.map.path = argv[1];
	parse_map(&data.map);
	ft_printf("2 %p\n", data.image[0].image);
	get_win_propertys(&data.map, &data.win_width, &data.win_height);
	ft_printf("3 %p\n", data.image[0].image);
	data.mlx.win = mlx_new_window(data.mlx.init, data.win_width, \
		data.win_height, "SO LONG");
	ft_printf("4 %p\n", data.image[0].image);
	mlx_clear_window(data.mlx.init, data.mlx.win);
	ft_printf("5 %p\n", data.image[0].image);
	mlx_put_image_to_window(data.mlx.init, data.mlx.win, \
		data.image[0].image, 0, 0);
	ft_printf("6 %p\n", data.image[0].image);
	mlx_loop(data.mlx.init);
	ft_printf("7 %p\n", data.image[0].image);
	system("leaks so_long");
	return (EXIT_SUCCESS);
}
