/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:08:18 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/25 02:37:00 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (i + ft_strlen(little) <= ft_strlen(big))
	{
		j = 0;
		while (j < ft_strlen(little))
		{
			if (j + 1 == ft_strlen(little) && big[i + j] == little[j])
				return (&((char *)big)[i]);
			if (i + j + 1 == len)
				return (NULL);
			if (big[i + j] != little[j])
				break ;
			j++;
		}
		i++;
	}
	return (NULL);
}
