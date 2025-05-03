/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy < lulmaruy@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 17:49:52 by lulmaruy          #+#    #+#             */
/*   Updated: 2024/11/10 16:58:55 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}

/*
#include <stdio.h>
int	main(void)
{
	unsigned char	s[] = "hello";
	int	c = 5;
	size_t	n = 5;
	size_t	i = 0;

	ft_memset(s, c, n);

	while (i < n)
	{
		printf("%d\n", s[i]);
		i++;
	}
}
*/
