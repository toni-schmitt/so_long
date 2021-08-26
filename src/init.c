/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 23:29:05 by tschmitt          #+#    #+#             */
/*   Updated: 2021/08/26 23:51:23 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_corner_textures(t_data *data)
{
	data->images[bottom_left].path = "../textures/corners/bottom_left.xpm";
	data->images[bottom_right].path = "../textures/corners/bottom_right.xpm";
	data->images[bottom].path = "../textures/corners/bottom.xpm";
	data->images[left].path = "../textures/corners/left.xpm";
	data->images[right].path = "../textures/corners/right.xpm";
	data->images[top_right].path = "../textures/corners/top_right.xpm";
	data->images[top].path = "../textures/corners/top.xpm";
	data->images[up_left].path = "../textures/corners/up_left.xpm";
}

static void	init_floor_textures(t_data *data)
{
	data->images[brick_mid].path = "../textures/floor/brick_mid.xpm";
	data->images[brick_straight].path = "../textures/floor/brick_straight.xpm";
	data->images[grass_empty].path = "../textures/floor/grass_empty.xpm";
	data->images[grass_flower].path = "../textures/floor/grass_flower.xpm";
	data->images[grass_half].path = "../textures/floor/grass_half.xpm";
	data->images[grass_quater].path = "../textures/floor/grass_quater.xpm";
	data->images[stone_mid].path = "../textures/floor/stone_mid.xpm";
	data->images[stone_straight].path = "../textures/floor/stone_straight.xpm";
}

static void	init_sprite_textures(t_data *data)
{
	data->images[castle].path = "../textures/sprites/castle.xpm";
	data->images[chest].path = "../textures/sprites/chest.xpm";
	data->images[door_iron].path = "../textures/sprites/door_iron.xpm";
	data->images[door_passage].path = "../textures/sprites/door_passage.xpm";
	data->images[door_wood].path = "../textures/sprites/door_wood.xpm";
	data->images[fire_0].path = "../textures/sprites/fire_0.xpm";
	data->images[fire_1].path = "../textures/sprites/fire_1.xpm";
	data->images[grass].path = "../textures/sprites/grass.xpm";
	data->images[map].path = "../textures/sprites/map.xpm";
	data->images[pot].path = "../textures/sprites/pot.xpm";
	data->images[rocks].path = "../textures/sprites/rocks.xpm";
	data->images[stairs_down].path = "../textures/sprites/stairs_down.xpm";
	data->images[stairs_up].path = "../textures/sprites/stairs_up.xpm";
	data->images[statue].path = "../textures/sprites/statue.xpm";
	data->images[throne].path = "../textures/sprites/throne.xpm";
	data->images[tree_0].path = "../textures/sprites/tree_0.xpm";
	data->images[tree_1].path = "../textures/sprites/tree_1.xpm";
	data->images[tree_2].path = "../textures/sprites/tree_2.xpm";
	data->images[trees_0].path = "../textures/sprites/trees_0.xpm";
	data->images[village].path = "../textures/sprites/village.xpm";
	data->images[well].path = "../textures/sprites/well.xpm";
}

static void	init_wall_textures(t_data *data)
{
	data->images[brick_down].path = "../textures/wall/brick_down.xpm";
	data->images[brick_up].path = "../textures/wall/brick_up.xpm";
	data->images[mossy_stone_wall].path = \
	"../textures/wall/mossy_stone_wall.xpm";
	data->images[stone_down].path = "../textures/wall/stone_down.xpm";
	data->images[stone_up].path = "../textures/wall/stone_up.xpm";
}

void	init_texture_paths(t_data *data)
{
	init_corner_textures(data);
	init_floor_textures(data);
	init_sprite_textures(data);
	init_wall_textures(data);
}
