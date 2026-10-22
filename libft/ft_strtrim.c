/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 19:11:05 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/29 00:03:36 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	is_in_set(const char *set, const char c)
{
	size_t	i;
	size_t	l_set;

	i = 0;
	l_set = ft_strlen(set);
	while (i < l_set)
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	head;
	size_t	tail;
	size_t	l_s1;
	char	*str;

	head = 0;
	tail = 0;
	l_s1 = ft_strlen(s1);
	while (is_in_set(set, s1[head]))
		head++;
	if (l_s1 == head)
		return (ft_strdup(""));
	while (is_in_set(set, s1[l_s1 - tail - 1]))
		tail++;
	str = ft_substr(s1, head, l_s1 - head - tail);
	if (str == NULL)
		return (NULL);
	return (str);
}
