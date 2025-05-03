/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 19:43:34 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/02 21:04:33 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	valid_col(char *line, char wall, t_data *data)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	if (line[0] != wall || line[i - 1] != wall)
	{
		ft_putendl_fd("Error\nWall missing in map column", 2);
		return (0);
	}
	data->width = i;
	return (1);
}

int	valid_line(char *line, char wall)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != wall)
		{
			ft_putendl_fd("Error\nWall missing in top or bottom line", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

int	valid_num(char *line, t_emt *element)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (element->ct_e > 1 || element->ct_p > 1)
		{
			ft_putendl_fd("Error\nExit/Player is more than 1", 2);
			return (0);
		}
		if (line[i] != element->wall && line[i] != element->player
			&& line[i] != element->exit && line[i] != element->collect
			&& line[i] != element->space)
		{
			ft_putendl_fd("Error\nUnknown symbol(s) in map", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

void	valid_element(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->element.collect)
				data->element.ct_c += 1;
			if (data->map[y][x] == data->element.player)
				data->element.ct_p += 1;
			if (data->map[y][x] == data->element.exit)
				data->element.ct_e += 1;
			x++;
		}
		x = 0;
		y++;
	}
}

int	valid_format(char **map)
{
	int	y;
	int	x;
	int	ct_x;

	y = 0;
	x = 0;
	ct_x = 0;
	while (map[0][ct_x])
		ct_x++;
	while (map[y] != NULL)
	{
		while (map[y][x])
			x++;
		if (x != ct_x)
		{
			ft_putendl_fd("Error\nmap must be rectangular", 2);
			return (0);
		}
		x = 0;
		y++;
	}
	return (1);
}
