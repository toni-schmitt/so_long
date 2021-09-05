/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:56:42 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 17:08:20 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	hanle_input(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		return (close_window(data));
	if (key == KEY_W)
		return (move_player(data, 0, -1));
	if (key == KEY_S)
		return (move_player(data, 0, +1));
	if (key == KEY_A)
		return (move_player(data, -1, 0));
	if (key == KEY_D)
		return (move_player(data, +1, 0));
	return (-1);
}
