/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:20:32 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/25 21:41:38 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_images(t_data *data)
{
	data->image[ground].image = mlx_xpm_file_to_image(data->mlx.init, \
	"../img/ground.xpm", &data->image[ground].width, \
	&data->image[ground].height);
	data->image[key].image = mlx_xpm_file_to_image(data->mlx.init, \
	"../img/key.xpm", &data->image[key].width, \
	&data->image[key].height);
	data->image[link_left].image = mlx_xpm_file_to_image(data->mlx.init, \
	"../img/link_left.xpm", &data->image[link_left].width, \
	&data->image[link_left].height);
	data->image[link_right].image = mlx_xpm_file_to_image(data->mlx.init, \
	"../img/link_right.xpm", &data->image[link_right].width, \
	&data->image[link_right].height);
	data->image[link_up].image = mlx_xpm_file_to_image(data->mlx.init, \
	"../img/link_up.xpm", &data->image[link_up].width, \
	&data->image[link_up].height);
	data->image[link1].image = mlx_xpm_file_to_image(data->mlx.init, \
	"../img/link1.xpm", &data->image[link1].width, \
	&data->image[link1].height);
	data->image[tent].image = mlx_xpm_file_to_image(data->mlx.init, \
	"../img/tent.xpm", &data->image[tent].width, \
	&data->image[tent].height);
	data->image[tree].image = mlx_xpm_file_to_image(data->mlx.init, \
	"../img/tree.xpm", &data->image[tree].width, \
	&data->image[tree].height);
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
	data.map.path = argv[1];
	parse_map(&data.map);
	get_win_propertys(&data.map, &data.win_width, &data.win_height);
	data.mlx.win = mlx_new_window(data.mlx.init, data.win_width, \
		data.win_height, "SO LONG");
	mlx_loop(data.mlx.init);
	return (EXIT_SUCCESS);
}
