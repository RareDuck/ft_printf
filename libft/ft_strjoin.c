/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 19:10:22 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/26 04:17:39 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	l_s1;
	size_t	l_s2;
	char	*str;

	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	str = ft_calloc(1, l_s1 + l_s2 + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcat(str, s1, l_s1 + l_s2 + 1);
	ft_strlcat(str, s2, l_s1 + l_s2 + 1);
	return (str);
}
