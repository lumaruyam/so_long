/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 17:01:02 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/05/01 16:54:15 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

char	*handle_read_errors(int ct_char, char **line, char **buff)
{
	if (ct_char < 0)
	{
		ft_putendl_fd("Error\nin reading map", 2);
		free(*line);
		free(*buff);
		return (NULL);
	}
	else if (ct_char == 0 && (*line == NULL || **line == '\0'))
	{
		ft_putendl_fd("Error\nmap is empty", 2);
		free(*line);
		free(*buff);
		return (NULL);
	}
	return (*buff);
}

char	*process_map(int fd, char *buff, char *line)
{
	char	*tmp_buff;
	int		ct_char;

	tmp_buff = buff;
	ct_char = 1;
	while (ct_char > 0)
	{
		buff = ft_strjoin(buff, line);
		free(tmp_buff);
		free(line);
		line = ft_strdup("");
		ct_char = get_next_line(fd, &line);
		tmp_buff = buff;
	}
	free(line);
	close(fd);
	return (buff);
}

char	*get_map(int fd)
{
	char	*line;
	char	*buff;
	int		ct_char;

	line = ft_strdup("");
	buff = ft_strdup("");
	if (!line || !buff)
	{
		free(line);
		free(buff);
		return (NULL);
	}
	ct_char = get_next_line(fd, &line);
	if (handle_read_errors(ct_char, &line, &buff) == NULL)
		return (NULL);
	if (ct_char > 0)
		return (process_map(fd, buff, line));
	free(line);
	free(buff);
	close(fd);
	ft_putendl_fd("Error\nin reading map", 2);
	return (NULL);
}

char	**valid_map(int fd, t_data *data)
{
	int		i;
	char	*map_str;

	i = 0;
	map_str = get_map(fd);
	if (map_str == NULL)
		return (NULL);
	data->map = ft_split(map_str, '\n');
	free(map_str);
	valid_element(data);
	if (!(valid_format(data->map)))
		return (ft_free_map(data));
	if (!(valid_line(data->map[0], data->element.wall)))
		return (ft_free_map(data));
	while (data->map[++i] != NULL)
	{
		if (!(valid_col(data->map[i], data->element.wall, data)))
			return (ft_free_map(data));
		else if (!(valid_num(data->map[i], &(data->element))))
			return (ft_free_map(data));
	}
	data->height = i;
	if (!(valid_line(data->map[i - 1], data->element.wall)) || !chk_path(data))
		return (ft_free_map(data));
	return (data->map);
}

char	**init_map(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (ft_str_find(str[1], ".ber") == 0)
		ft_putendl_fd("Error\nwrong map format", 2);
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = valid_map(fd, data);
		else
			ft_putendl_fd("Error\nFailed to open file", 2);
		if (data->map && !chk_path(data))
			ft_free_map(data);
		if ((data->element.ct_c == 0 || data->element.ct_e != 1
				|| data->element.ct_p != 1) && data->map != NULL)
		{
			ft_free_map(data);
			ft_putendl_fd("Error\nput 1 player/exit & 1+ collect", 2);
		}
	}
	return (data->map);
}
