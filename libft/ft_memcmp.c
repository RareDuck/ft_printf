/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:19:14 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/25 02:40:28 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	c1;
	unsigned char	c2;

	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		c1 = *(unsigned char *)(s1 + i);
		c2 = *(unsigned char *)(s2 + i);
		if (c1 != c2)
			return (c1 - c2);
		i++;
	}
	return (0);
}
