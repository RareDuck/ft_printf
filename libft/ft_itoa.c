/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/25 14:27:57 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/29 00:31:06 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	digit_counter(int n)
{
	long	n_dup;
	size_t	i;

	n_dup = (long)n;
	i = 0;
	if (n_dup == 0)
		i++;
	if (n_dup < 0)
	{
		i++;
		n_dup *= -1;
	}
	while (n_dup > 0)
	{
		n_dup /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	n_dup;
	size_t	str_len;
	char	*str;

	n_dup = (long)n;
	str_len = digit_counter(n);
	str = malloc(str_len + 1);
	if (str == NULL)
		return (NULL);
	str[str_len] = '\0';
	if (n_dup == 0)
		str[0] = '0';
	if (n_dup < 0)
	{
		str[0] = '-';
		str_len--;
		n_dup *= -1;
	}
	while (n_dup > 0)
	{
		str[(str_len-- - 1) + 1 * (str[0] == '-')] = n_dup % 10 + 48;
		n_dup /= 10;
	}
	return (str);
}
