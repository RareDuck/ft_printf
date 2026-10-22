/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:11:11 by NEMO              #+#    #+#             */
/*   Updated: 2026/10/01 21:46:25 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*buffer;

	if (size != 0 && n > ((size_t) - 1) / size)
		return (NULL);
	buffer = malloc (n * size);
	if (buffer == NULL)
		return (NULL);
	return (ft_memset(buffer, 0, n * size));
}
