/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 14:52:18 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/30 20:37:27 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	set_element(t_emt *element)
{
	element->exit = 'E';
	element->player = 'P';
	element->wall = '1';
	element->space = '0';
	element->collect = 'C';
	element->ct_p = 0;
	element->ct_e = 0;
	element->ct_c = 0;
}

int	gamewindow_oversize(t_data *data, int width, int height)
{
	int		scrn_width;
	int		scrn_height;

	scrn_width = 0;
	scrn_height = 0;
	mlx_get_screen_size(data->mlx_ptr, &scrn_width, &scrn_height);
	if (width > scrn_width || height > scrn_height)
		return (1);
	return (0);
}

int	valid_img(t_data *data)
{
	if (data->img.img_wall == NULL || data->img.img_floor == NULL
		|| data->img.img_exit == NULL || data->img.img_collect == NULL
		|| data->img.img_player == NULL)
		return (1);
	return (0);
}

void	set_img(t_data *data)
{
	data->img.height = 80;
	data->img.width = 80;
	data->img.floor = "./textures/floor.xpm";
	data->img.wall = "./textures/wall.xpm";
	data->img.collect = "./textures/collect.xpm";
	data->img.player = "./textures/player.xpm";
	data->img.exit = "./textures/exit.xpm";
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&(data->img.width), &(data->img.height));
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&(data->img.width), &(data->img.height));
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&(data->img.width), &(data->img.height));
	data->img.img_collect = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collect, &(data->img.width), &(data->img.height));
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &(data->img.width), &(data->img.height));
	if (valid_img(data))
	{
		ft_putendl_fd("Error\nInvalid image", 2);
		end(data);
	}
}
