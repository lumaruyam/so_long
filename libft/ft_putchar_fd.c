/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:32:56 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/03/25 20:10:11 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*
#include <stdio.h>
int	main()
{
	char	c = 'a';
	int	fd = 1;

	ft_putchar_fd(c, fd);
	return (0);
}
*/
