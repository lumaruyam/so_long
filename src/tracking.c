/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tracking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 20:18:04 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/26 16:40:23 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	flood_fill(char **map, int x, int y, t_emt *e)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == e->collect)
		e->ct_c--;
	if (map[y][x] == e->exit)
		e->ct_e--;
	if (map[y][x] == e->exit && e->ct_c != 0)
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y, e);
	flood_fill(map, x - 1, y, e);
	flood_fill(map, x, y + 1, e);
	flood_fill(map, x, y - 1, e);
}

int	get_player_pos(t_data *data, int *px, int *py, t_emt e)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == e.player)
			{
				*px = x;
				*py = y;
				return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	chk_path(t_data *data)
{
	char	**map_copy;
	t_emt	e;
	int		px;
	int		py;

	map_copy = ft_dup_map(data->map);
	if (!map_copy)
		return (ft_putendl_fd("Error\nMemory allocation failed", 2), 0);
	e = data->element;
	if (!get_player_pos(data, &px, &py, e))
	{
		ft_free_map_copy(map_copy);
		return (ft_putendl_fd("Error\nPlayer not found", 2), 0);
	}
	flood_fill(map_copy, px, py, &e);
	ft_free_map_copy(map_copy);
	if (e.ct_c == 0 && e.ct_e == 0)
		return (1);
	ft_putendl_fd("Error\nUnreachable collect or exit", 2);
	return (0);
}
