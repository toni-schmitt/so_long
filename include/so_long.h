/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:21:00 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 16:52:51 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "keys.h"
# include <mlx.h>
# include <fcntl.h>

# ifndef WIN_WIDTH
#  define WIN_WIDTH 1000
# endif
# ifndef WIN_HEIGHT
#  define WIN_HEIGHT 1000
# endif

# define NO_OF_TEXTURES 6
# define TEXTURE_WIDTH 32
# define TEXTURE_HEIGHT 32

enum
{
	player = 0,
	map_exit = 1,
	collectible = 2,
	wall = 3,
};

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char		*path;
	char		**data;
	int			line_count;
	t_vector	*positions[4];
	int			pos_count[4];
	int			movement_counter;
	int			collected;
}	t_map;

typedef struct s_mlx
{
	void	*init;
	void	*win;
}	t_mlx;

enum e_textures {
	grass_flower = 0,
	stone_down = 1,
	stone_up = 2,
	chest = 3,
	statue = 4,
	stairs_down = 5
};

typedef struct s_image
{
	void		*image;
	t_vector	size;
	char		*pixels;
	int			bpp;
	int			line_size;
	int			endian;
	char		*path;
	int			is_valid;
}	t_image;

typedef struct s_data
{
	t_mlx	mlx;
	t_image	images[NO_OF_TEXTURES];
	t_map	map;
	int		win_width;
	int		win_height;
}	t_data;

/* PARSE_MAP */
void	parse_map(t_map *map);

/* VALIDATE_MAP */
void	validate_map(char **map_data, int line_count);

/* DRAW_MAP */
void	draw_map(t_data *data);

/* HANDLE_KEYS */
int		handle_keys(int key, t_data *data);

/* FREE_UTILS */
int		free_images(t_data *data, int exit_status);
int		free_map_data(char **data, int exit_status);
int		free_data(t_data *data, int exit_status);

/* UTILS */
int		close_window(t_data *data);
void	new_sprite(void *mlx, t_image *image);
void	put_image(t_data *data, int image, unsigned int x, unsigned int y);
void	init_texture_paths(t_data *data);
void	init_positions(t_map *map);
int		win_game(t_data *data);

#endif
