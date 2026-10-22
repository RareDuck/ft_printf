/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 15:55:34 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/28 21:07:57 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	size_t	i;

	if (dest == NULL)
		return (NULL);
	i = 0;
	while (i < count)
	{
		*((char *)dest + i) = (char)c;
		i++;
	}
	return (dest);
}
