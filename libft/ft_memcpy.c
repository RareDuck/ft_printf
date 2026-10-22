/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:00:02 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/26 05:08:57 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t	i;

	if (dest == NULL)
		return (NULL);
	if (src == NULL)
		return (dest);
	i = 0;
	while (i < count)
	{
		if (src + i == NULL)
			return (dest);
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}
