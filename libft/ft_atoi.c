/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:24:07 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/28 17:22:07 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_separator(char c)
{
	if ((9 <= c && c <= 13)
		|| c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		is_neg;
	long	integer;

	i = 0;
	is_neg = 0;
	integer = 0;
	while (is_separator(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg++;
		i++;
	}
	while (str[i] != '\0'
		&& ('0' <= str[i]
			&& str[i] <= '9'))
	{
		integer *= 10;
		integer += (str[i] - 48);
		i++;
	}
	return ((int)integer * (1 - 2 * (is_neg)));
}
