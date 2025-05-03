/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 20:54:22 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/03 21:13:08 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_stradd(char *str, char buff)
{
	int		i;
	char	*ret;

	if (!str)
		return (NULL);
	i = 0;
	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (ret == NULL)
	{
		free(str);
		return (NULL);
	}
	while (str[i])
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buff;
	ret[++i] = '\0';
	return (ret);
}

int	get_next_line(int fd, char **str)
{
	char	buff;
	int		ret;

	if (!str || fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	if (!*str)
		*str = ft_strdup("");
	if (!*str)
		return (-1);
	ret = read(fd, &buff, 1);
	while (ret > 0)
	{
		*str = ft_stradd(*str, buff);
		if (!*str)
			return (-1);
		if (buff == '\n')
			return (1);
		ret = read(fd, &buff, 1);
	}
	if (ret == 0 && *str && **str)
		return (1);
	free(*str);
	*str = NULL;
	return (ret);
}

// char	*ft_stradd(char *str, char buff)
// {
// 	int		i;
// 	char	*ret;

// 	i = 0;
// 	ret = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
// 	if (ret == NULL)
// 		return (NULL);
// 	while (str[i])
// 	{
// 		ret[i] = str[i];
// 		i++;
// 	}
// 	free(str);
// 	ret[i] = buff;
// 	ret[++i] = '\0';
// 	return (ret);
// }

// int	get_next_line(int fd, char **str)
// {
// 	char			buff;
// 	int				ret;

// 	ret = read(fd, &buff, 1);
// 	while (ret > 0)
// 	{
// 		*str = ft_stradd(*str, buff);
// 		if (buff == '\n')
// 			return (ret);
// 		else
// 			ret += 1;
// 		ret = read(fd, &buff, 1);
// 	}
// 	if (ret == 0)
// 	{
// 		free(*str);
// 		*str = NULL;
// 	}
// 	return (ret);
// }

// static int	verify_new_line(char **backup, char **line)
// {
// 	char	*tmp;
// 	int		i;

// 	i = 0;
// 	while ((*backup)[i] != '\n' && (*backup)[i] != '\0')
// 		i++;
// 	if ((*backup)[i] == '\0')
// 		return (0);
// 	*line = ft_substr(*backup, 0, i);

// 	tmp = ft_strdup(*backup + i + 1);
// 	free(*backup);
// 	*backup = tmp;
// 	return (1);
// }

// static char	*file_read(int fd, char *buf, char *backup)
// {
// 	int		read_line;
// 	char	*tmp;

// 	read_line = read(fd, buf, BUFFER_SIZE);
// 	while (read_line > 0)
// 	{
// 		buf[read_line] = '\0';
// 		if (!backup)
// 			backup = ft_strdup("");
// 		tmp = backup;
// 		backup = ft_strjoin(tmp, buf);
// 		free(tmp);
// 		if (ft_strchr(buf, '\n'))
// 			break ;
// 		read_line = read(fd, buf, BUFFER_SIZE);
// 	}
// 	return (backup);
// }

// int	get_next_line(int fd, char **line)
// {
// 	char		*buf;
// 	static char	*backup[FD_MAX];

// 	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX - 1 || !line)
// 		return (-1);
// 	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
// 	if (!buf)
// 		return (-1);
// 	backup[fd] = file_read(fd, buf, backup[fd]);
// 	free(buf);
// 	if (!backup[fd] || *backup[fd] == '\0')
// 	{
// 		free(backup[fd]);
// 		backup[fd] = NULL;
// 		*line = NULL;
// 		return (0);
// 	}
// 	if (verify_new_line(&backup[fd], line))
// 		return (1);
// 	*line = ft_strdup(backup[fd]);
// 	free(backup[fd]);
// 	backup[fd] = NULL;
// 	return (1);
// }

/*
#include <stdio.h>
int	main()
{
	int	fd = open("./tst.txt", O_RDONLY);
	char	*line;

	while ((get_next_line(fd, &line)) > 0)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
	return (0);
}
*/
