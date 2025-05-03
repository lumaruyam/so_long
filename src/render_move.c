/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 18:23:15 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/03/25 20:16:02 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	render_top(t_data *data)
{
	int	x;
	int	y;

	x = data->pos.x / data->img.width;
	y = data->pos.y / data->img.height;
	if (data->map[y - 1][x] != data->element.wall)
	{
		if (data->map[y - 1][x] != data->element.exit)
		{
			data->map[y - 1][x] = data->element.player;
			data->map[y][x] = data->element.space;
			data->ct_mv += 1;
			ft_printf("move count: %d\n", data->ct_mv);
		}
		else
		{
			if (ct_collect(data) == 0)
			{
				ft_printf("You collected all with %d move!\n", data->ct_mv);
				end(data);
			}
		}
	}
}

void	render_right(t_data *data)
{
	int	x;
	int	y;

	x = data->pos.x / data->img.width;
	y = data->pos.y / data->img.height;
	if (data->map[y][x + 1] != data->element.wall)
	{
		if (data->map[y][x + 1] != data->element.exit)
		{
			data->map[y][x + 1] = data->element.player;
			data->map[y][x] = data->element.space;
			data->ct_mv += 1;
			ft_printf("move count: %d\n", data->ct_mv);
		}
		else
		{
			if (ct_collect(data) == 0)
			{
				ft_printf("You collected all with %d move!\n", data->ct_mv);
				end(data);
			}
		}
	}
}

void	render_left(t_data *data)
{
	int	x;
	int	y;

	x = data->pos.x / data->img.width;
	y = data->pos.y / data->img.height;
	if (data->map[y][x - 1] != data->element.wall)
	{
		if (data->map[y][x - 1] != data->element.exit)
		{
			data->map[y][x - 1] = data->element.player;
			data->map[y][x] = data->element.space;
			data->ct_mv += 1;
			ft_printf("move count: %d\n", data->ct_mv);
		}
		else
		{
			if (ct_collect(data) == 0)
			{
				ft_printf("You collected all with %d move!\n", data->ct_mv);
				end(data);
			}
		}
	}
}

void	render_down(t_data *data)
{
	int	x;
	int	y;

	x = data->pos.x / data->img.width;
	y = data->pos.y / data->img.height;
	if (data->map[y + 1][x] != data->element.wall)
	{
		if (data->map[y + 1][x] != data->element.exit)
		{
			data->map[y + 1][x] = data->element.player;
			data->map[y][x] = data->element.space;
			data->ct_mv += 1;
			ft_printf("move count: %d\n", data->ct_mv);
		}
		else
		{
			if (ct_collect(data) == 0)
			{
				ft_printf("You collected all with %d move!\n", data->ct_mv);
				end(data);
			}
		}
	}
}
