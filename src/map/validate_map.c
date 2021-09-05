/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tschmitt <tschmitt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:11:56 by tschmitt          #+#    #+#             */
/*   Updated: 2021/09/05 19:16:21 by tschmitt         ###   ########.fr       */
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

static int	has_correct_chars(char *data, int *count)
{
	while (data && *data)
	{
		if (*data == 'P')
			count[0]++;
		if (*data == 'E')
			count[1]++;
		if (*data == 'C')
			count[2]++;
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

static int	is_valid(char **map_data, int line_count)
{
	int	count[3];
	int	i;

	i = 0;
	count[0] = 0;
	count[1] = 0;
	count[2] = 0;
	while (map_data[i])
	{
		if (i != line_count - 1)
			if (ft_strlen(map_data[i]) != ft_strlen(map_data[i + 1]))
				return (FALSE);
		if (i == 0 || i == line_count - 1)
			if (!is_correct_horizontal_wall(map_data[i]))
				return (FALSE);
		if (!is_correct_vertical_wall(map_data[i]))
			return (ft_puterror("Map has no valid walls"));
		if (!has_correct_chars(map_data[i], count))
			return (ft_puterror("Map has not supported chars"));
		i++;
	}
	if (count[0] < 1 || count[1] < 1 || count[2] < 1)
		return (FALSE);
	return (TRUE);
}

void	validate_map(char **map_data, int line_count)
{
	if (!is_valid(map_data, line_count))
		ft_puterror("Map is not valid!");
}
