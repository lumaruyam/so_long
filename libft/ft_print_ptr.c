/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 21:34:49 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/03/25 20:11:44 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_ptr(long unsigned n)
{
	long unsigned	tmp;
	char			res[256];
	int				i;
	int				ct;

	i = 0;
	ct = 0;
	if (!n)
	{
		ft_print_str("(nil)");
		return (5);
	}
	while (n > 0)
	{
		tmp = n % 16;
		res[i++] = "0123456789abcdef"[tmp];
		n /= 16;
	}
	ct += write(1, "0x", 2);
	while (--i >= 0)
		ct += write(1, &res[i], 1);
	return (ct);
}
