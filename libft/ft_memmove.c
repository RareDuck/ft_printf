/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:57:12 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/30 13:39:38 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	if (dest == NULL)
		return (NULL);
	if (count == 0)
		return (dest);
	if (src > dest)
		dest = ft_memcpy(dest, src, count);
	else
	{
		while (1)
		{
			count--;
			*((char *)dest + count) = *((char *)src + count);
			if (count == 0)
				break ;
		}
	}
	return (dest);
}
