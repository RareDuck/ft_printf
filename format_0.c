/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_0.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:25:05 by ayague-a          #+#    #+#             */
/*   Updated: 2026/10/06 11:49:52 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_c(char **ptr, int *out, va_list args)
{
	char	c;

	c = va_arg(args, int);
	ft_putchar_fd(c, 1);
	(*ptr)++;
	(*out)++;
}

void	format_s(char **ptr, int *out, va_list args)
{
	char	*str;
	int		str_len;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	str_len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	(*ptr)++;
	*out += str_len;
}

void	format_p(char **ptr, int *out, va_list args)
{
	void		*temp;
	uintptr_t	p;

	(*ptr)++;
	temp = va_arg(args, void *);
	if (temp == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		*out += 5;
	}
	else
	{
		ft_putstr_fd("0x", 1);
		p = (uintptr_t)temp;
		*out += ft_putptr_fd(p, 1) + 2;
	}
}
