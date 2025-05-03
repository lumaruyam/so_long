/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 21:17:43 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/28 20:10:17 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

typedef struct s_img
{
	int		height;
	int		width;
	void	*img_floor;
	void	*img_player;
	void	*img_exit;
	void	*img_wall;
	void	*img_collect;
	char	*exit;
	char	*collect;
	char	*player;
	char	*wall;
	char	*floor;
}	t_img;

typedef struct s_emt
{
	char	exit;
	char	collect;
	char	player;
	char	wall;
	char	space;
	int		ct_p;
	int		ct_e;
	int		ct_c;
}	t_emt;

typedef struct s_pos
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		height;
	int		width;
	char	**map;
	t_emt	element;
	t_img	img;
	t_pos	pos;
	int		ct_mv;
}	t_data;

int		ct_collect(t_data *data);
int		end(t_data *data);
int		key_press(int keystm, t_data *data);

char	*get_map(int fd);
void	*ft_free_map(t_data *data);
char	*handle_read_errors(int ct_char, char **line, char **buff);
char	*process_map(int fd, char *buff, char *line);
char	**valid_map(int fd, t_data *data);
char	**init_map(char **str, t_data *data);

void	render_top(t_data *data);
void	render_right(t_data *data);
void	render_left(t_data *data);
void	render_down(t_data *data);

void	render_backgroud(t_data *data);

void	put_img(t_data *data, void *img, int x, int y);
void	render_element(t_data *data);
int		render(t_data *data);
void	main_render(t_data *data);

void	set_element(t_emt *element);
void	set_img(t_data *data);
int		valid_img(t_data *data);
int		gamewindow_oversize(t_data *data, int width, int height);

int		valid_col(char *line, char wall, t_data *data);
int		valid_line(char *line, char wall);
int		valid_num(char *line, t_emt *element);
void	valid_element(t_data *data);
int		valid_format(char **map);

int		chk_path(t_data *data);
int		get_player_pos(t_data *data, int *px, int *py, t_emt e);
void	flood_fill(char **map, int x, int y, t_emt *e);

int		ft_str_find(char *s1, char *s2);
void	*ft_error(char *str);
char	**ft_dup_map(char **map);
void	ft_free_map_copy(char **map);

#endif
