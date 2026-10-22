/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:52:41 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/25 00:55:28 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	s_src;
	size_t	s_dst;
	size_t	i;

	s_src = ft_strlen(src);
	s_dst = ft_strlen(dst);
	i = 0;
	if (size > 1)
	{
		i += s_dst;
		while ((i < size - 1) && (i < s_src + s_dst))
		{
			dst[i] = src[i - s_dst];
			i++;
		}
		if (i != size)
			dst[i] = '\0';
	}
	if (s_dst <= size)
		return (s_src + s_dst);
	return (s_src + size);
}
