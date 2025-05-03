/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:46:04 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/02/08 17:22:57 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(int nb)
{
	t_list	*new;

	new = malloc(sizeof(t_list) * 1);
	if (!new)
		return (NULL);
	new->nb = nb;
	new->next = NULL;
	return (new);
}

/*
#include <stdio.h>
int	main()
{
	char	new_cnt[] = "hello";
	t_list	*node;

	node = ft_lstnew((void *)new_cnt);
	printf("%s\n", (char *)node->content);
	printf("%p\n", (void *)node->next);
	free(node);
	return (0);
}
*/
