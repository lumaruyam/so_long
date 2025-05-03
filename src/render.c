/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/23 17:10:17 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/28 21:08:19 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	put_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, img,
		data->img.width * x, data->img.height * y);
}

void	render_background(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->element.wall)
				put_img(data, data->img.img_wall, x, y);
			if (data->map[y][x] == data->element.space)
				put_img(data, data->img.img_floor, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

void	render_element(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y] != NULL)
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->element.collect)
				put_img(data, data->img.img_collect, x, y);
			if (data->map[y][x] == data->element.player)
			{
				data->pos.x = x * data->img.width;
				data->pos.y = y * data->img.height;
				put_img(data, data->img.img_player, x, y);
			}
			if (data->map[y][x] == data->element.exit)
				put_img(data, data->img.img_exit, x, y);
			x++;
		}
		x = 0;
		y++;
	}
}

int	render(t_data *data)
{
	render_background(data);
	render_element(data);
	return (0);
}

void	main_render(t_data *data)
{
	int	win_width;
	int	win_height;

	win_width = data->width * data->img.width;
	win_height = data->height * data->img.height;
	data->mlx_win = mlx_new_window(data->mlx_ptr, win_width,
			win_height, "So_long");
	if (data->mlx_win == NULL)
	{
		free(data->mlx_ptr);
		return ;
	}
	if (gamewindow_oversize(data, win_width, win_height))
	{
		ft_putendl_fd("Error\nGame window is too big for your screen", 2);
		end(data);
		return ;
	}
	render(data);
	mlx_loop_hook(data->mlx_ptr, &render, data);
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, &key_press, data);
	mlx_hook(data->mlx_win, 17, 0, &end, data);
	mlx_loop(data->mlx_ptr);
	end(data);
}
