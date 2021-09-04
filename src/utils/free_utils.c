/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:52:48 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/04 19:00:00 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_images(t_data *data, int exit_status)
{
	int	i;

	i = 0;
	while (i < NO_OF_TEXTURES)
	{
		free(data->images[i].image);
		free(data->images[i].pixels);
		i++;
	}
	return (exit_status);
}

int	free_map_data(char **data, int exit_status)
{
	int	i;

	i = 0;
	while (data[i])
	{
		free(data[i]);
		i++;
	}
	free(data);
	return (exit_status);
}

int	free_map_positions(t_vector **positions, int exit_status)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(positions[i]);
		i++;
	}
	return (exit_status);
}

int	free_data(t_data *data, int exit_status)
{
	free(data->mlx.init);
	free_map_data(data->map.data, exit_status);
	free_map_positions(data->map.positions, exit_status);
	free_images(data, exit_status);
	return (exit_status);
}
