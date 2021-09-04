/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 14:56:42 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/04 15:02:57 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

enum
{
	up = 0,
	down = 1,
	left = 2,
	right = 3
};

static int	move(t_data *data, int direction)
{
	return (1);
}

int	handle_keys(int key, t_data *data)
{
	if (key == KEY_ESCAPE)
		return (close_window(data));
	if (key == KEY_W)
		return (move(data, up));
	if (key == KEY_S)
		return (move(data, down));
	if (key == KEY_A)
		return (move(data, left));
	if (key == KEY_D)
		return (move(data, right));
	return (-1);
}
