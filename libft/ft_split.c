/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 20:07:07 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/30 13:41:43 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	words_counter(const char *str, size_t s_len, char space)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (i < s_len)
	{
		if (str[i] != space)
		{
			words++;
			while (i < s_len && str[i] != space)
				i++;
		}
		if (str[i] == space)
			i++;
	}
	return (words);
}

static void	lst_deleter(char **arr, size_t words)
{
	while (arr[words] != NULL)
		free(arr[words++]);
	free(arr);
}

static char	**arr_generator(char const *s, char c, size_t words, char **arr)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < ft_strlen(s) && arr != NULL)
	{
		j = 0;
		while (s[ft_strlen(s) - 1 - (i)] == c && i < ft_strlen(s))
			i++;
		while (s[ft_strlen(s) - 1 - (i + j)] != c && (j + i) < ft_strlen(s) - 1)
			j++;
		j -= 1 * (s[ft_strlen(s) - 1 - (i + j)] == c);
		if (words > 0)
			arr[--words] = ft_substr(s, ft_strlen(s) - 1 - (i + j), j + 1);
		if (arr[words] == NULL)
		{
			lst_deleter(arr, words + 1);
			return (NULL);
		}
		i += j + 2;
	}
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	words;

	words = words_counter(s, ft_strlen(s), c);
	arr = ft_calloc(8, words + 1);
	if (arr == NULL)
		return (NULL);
	if (words != 0)
		arr = arr_generator(s, c, words, arr);
	return (arr);
}
