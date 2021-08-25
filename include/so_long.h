/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 16:21:00 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/25 19:37:06 by tschmitt         ###   ########.fr       */
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

enum e_img {
	ground,
	key,
	link_left,
	link_right,
	link_up,
	link1,
	tent,
	tree
};

typedef struct s_image
{
	void	*image;
	int		width;
	int		height;
}	t_image;

typedef struct s_data
{
	t_mlx	mlx;
	t_image	image[8];
	t_map	map;
	int		win_width;
	int		win_height;
}	t_data;

void	parse_map(t_map *map);

#endif