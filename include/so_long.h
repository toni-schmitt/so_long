/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:21:00 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/27 16:47:07 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include <mlx.h>
# include <fcntl.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1000
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1000
# endif

# define NO_OF_TEXTURES 42
# define TEXTURE_WIDTH 16
# define TEXTURE_HEIGHT 16

typedef struct s_map
{
	char	*path;
	char	**data;
}	t_map;

typedef struct s_mlx
{
	void	*init;
	void	*win;
}	t_mlx;

enum e_corners {
	bottom_left = 0,
	bottom_right = 1,
	bottom = 2,
	left = 3,
	right = 4,
	top_left = 5,
	top_right = 6,
	top = 7,
};

enum e_floor {
	brick_mid = 8,
	brick_straight = 9,
	grass_empty = 10,
	grass_flower = 11,
	grass_half = 12,
	grass_quater = 13,
	stone_mid = 14,
	stone_straight = 15,
};

enum e_sprites {
	castle = 16,
	chest = 17,
	door_iron = 18,
	door_passage = 19,
	door_wood = 20,
	fire_0 = 21,
	fire_1 = 22,
	grass = 23,
	map = 24,
	pot = 25,
	rocks = 26,
	stairs_down = 27,
	stairs_up = 28,
	statue = 29,
	throne = 30,
	tree_0 = 31,
	tree_1 = 32,
	tree_2 = 33,
	trees_0 = 34,
	village = 35,
	well = 36,
};

enum e_wall {
	brick_down = 37,
	brick_up = 38,
	mossy_stone_wall = 39,
	stone_down = 40,
	stone_up = 41,
};

typedef struct s_image
{
	void	*image;
	char	*path;
	int		is_valid;
	int		width;
	int		height;
}	t_image;

typedef struct s_data
{
	t_mlx	mlx;
	t_image	images[42];
	t_map	map;
	int		win_width;
	int		win_height;
}	t_data;

void	parse_map(t_map *map);
void	init_texture_paths(t_data *data);
void	draw_map(t_data *data);

#endif