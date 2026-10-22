/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:16:19 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/28 23:54:01 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	l_src;
	size_t	l_sub_str;
	char	*sub_str;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub_str = ft_strdup("");
		if (sub_str == NULL)
			return (NULL);
		return (sub_str);
	}
	l_src = ft_strlen(&s[start]);
	l_sub_str = len * (len <= l_src) + l_src * (l_src < len) + 1;
	sub_str = ft_calloc(l_sub_str, 1);
	if (sub_str == NULL)
		return (NULL);
	ft_strlcpy(sub_str, &s[start], l_sub_str);
	return (sub_str);
}
