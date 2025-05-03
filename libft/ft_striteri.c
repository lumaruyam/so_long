/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy < lulmaruy@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:01:09 by lulmaruy          #+#    #+#             */
/*   Updated: 2024/11/15 17:27:36 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>
void	ft_test(unsigned int i, char *c)
{
	i = 32;

	*c = *c - i;
}

int	main()
{
	char	s[] = "hello";

	ft_striteri(s, ft_test);
	printf("%s\n", s);
	return (0);
}
*/
