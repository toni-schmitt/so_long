/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:11:56 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/04 15:29:51 by tschmitt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_correct_vertical_wall(char *data)
{
	if (data[0] != '1')
		return (FALSE);
	if (data[ft_strlen(data) - 1] != '1')
		return (FALSE);
	return (TRUE);
}

static int	is_correct_horizontal_wall(char *data)
{
	while (data && *data)
	{
		if (*data != '1')
			return (FALSE);
		data++;
	}
	return (TRUE);
}

static int	has_correct_chars(char *data)
{
	while (data && *data)
	{
		if (*data < '0')
			return (FALSE);
		if (*data > '1' && *data < 'C')
			return (FALSE);
		if (*data > 'C' && *data < 'E')
			return (FALSE);
		if (*data > 'E' && *data < 'P')
			return (FALSE);
		if (*data > 'P')
			return (FALSE);
		data++;
	}
	return (TRUE);
}

static int	is_valid(char **map_data, int count)
{
	int	i;

	i = 0;
	while (map_data[i])
	{
		if (i == 0 || i == count - 1)
			if (!is_correct_horizontal_wall(map_data[i]))
				return (FALSE);
		if (!is_correct_vertical_wall(map_data[i]))
			return (ft_puterror("Map has no valid walls"));
		if (!has_correct_chars(map_data[i]))
			return (ft_puterror("Map has not supported chars"));
		i++;
	}
	return (TRUE);
}

void	validate_map(char **map_data, int line_count)
{
	if (!is_valid(map_data, line_count))
		ft_puterror("Map is not valid!");
}
