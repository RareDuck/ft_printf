/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 03:50:28 by ayague-a          #+#    #+#             */
/*   Updated: 2026/10/05 18:41:04 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	format_i(char **ptr, int *out, va_list args)
{
	int	nb;

	nb = va_arg(args, int);
	ft_putnbr_fd(nb, 1);
	(*ptr)++;
	if (nb <= 0)
		(*out)++;
	while (nb != 0)
	{
		nb /= 10;
		(*out)++;
	}
}

void	format_u(char **ptr, int *out, va_list args)
{
	long	nb;

	nb = va_arg(args, unsigned int);
	ft_putunbr_fd(nb, 1);
	(*ptr)++;
	if (nb == 0)
		(*out)++;
	while (nb != 0)
	{
		nb /= 10;
		(*out)++;
	}
}

void	format_x(char **ptr, int *out, va_list args)
{
	int		num;

	num = va_arg(args, int);
	(*ptr)++;
	*out += ft_puthex_fd(num, 0, 1);
}

void	format_xx(char **ptr, int *out, va_list args)
{
	int		num;

	num = va_arg(args, int);
	(*ptr)++;
	*out += ft_puthex_fd(num, 1, 1);
}

void	format_double(char **ptr, int *out)
{
	ft_putchar_fd('%', 1);
	(*ptr)++;
	(*out)++;
}
