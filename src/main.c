/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:24:51 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/30 20:36:20 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ct_collect(t_data *data)
{
	int	y;
	int	x;
	int	ct;

	y = 0;
	x = 0;
	ct = 0;
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if (data->map[y][x] == data->element.collect)
				ct++;
			x++;
		}
		x = 0;
		y++;
	}
	return (ct);
}

void	destroy_images(t_data *data)
{
	if (data->img.img_wall)
		mlx_destroy_image(data->mlx_ptr, data->img.img_wall);
	if (data->img.img_floor)
		mlx_destroy_image(data->mlx_ptr, data->img.img_floor);
	if (data->img.img_collect)
		mlx_destroy_image(data->mlx_ptr, data->img.img_collect);
	if (data->img.img_player)
		mlx_destroy_image(data->mlx_ptr, data->img.img_player);
	if (data->img.img_exit)
		mlx_destroy_image(data->mlx_ptr, data->img.img_exit);
}

int	end(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		destroy_images(data);
	}
	if (data->mlx_win)
		mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(0);
}

int	key_press(int keystm, t_data *data)
{
	if (keystm == XK_Escape)
		end(data);
	if (keystm == XK_w)
		render_top(data);
	if (keystm == XK_d)
		render_right(data);
	if (keystm == XK_a)
		render_left(data);
	if (keystm == XK_s)
		render_down(data);
	return (0);
}

int	main(int ac, char *av[])
{
	t_data	data;

	data = (t_data){0};
	if (ac != 2)
	{
		ft_putendl_fd("Error\nput 1 argument .ber file", 2);
		return (0);
	}
	else
	{
		data.ct_mv = 0;
		data.mlx_ptr = mlx_init();
		set_element(&(data.element));
		data.map = init_map(av, &data);
		if (!data.mlx_ptr)
			return (0);
		if (data.map != NULL)
		{
			set_img(&data);
			main_render(&data);
		}
		else
			end(&data);
	}
	return (1);
}
