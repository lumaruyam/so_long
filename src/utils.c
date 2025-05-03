/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 21:13:23 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/27 17:00:00 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

int	ft_str_find(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '\0' && s2[j] == '\0')
		return (1);
	while (s1[i])
	{
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j])
			j++;
		if (s1[i + j] == '\0' && s2[j] == '\0')
			return (1);
		else
			j = 0;
		i++;
	}
	return (0);
}

void	*ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (0);
}

char	**ft_dup_map(char **map)
{
	int		i;
	int		len;
	char	**copy;

	len = 0;
	while (map[len])
		len++;
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			while (--i >= 0)
				free(copy[i]);
			free(copy);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	ft_free_map_copy(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	*ft_free_map(t_data *data)
{
	int	i;

	if (data->map == NULL)
		return (NULL);
	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (NULL);
}
