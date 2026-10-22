/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: NEMO <NEMO@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 11:50:23 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/21 11:55:20 by NEMO             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_len;
	char			*str;

	i = 0;
	s_len = ft_strlen(s);
	str = malloc(s_len + 1);
	if (str == NULL)
		return (NULL);
	while (i < s_len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
