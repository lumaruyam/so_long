/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:49:45 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/04/02 21:00:24 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

/*
#include <stdio.h>
int	main()
{
	char	s[] = "hello";
	int	fd = 1;

	ft_putendl_fd(s, fd);
	return (0);
}
*/
