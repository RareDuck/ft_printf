/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 16:53:04 by ayague-a          #+#    #+#             */
/*   Updated: 2026/10/06 11:49:30 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_puthex_fd(unsigned int num, int iscap, int fd)
{
	int				out;
	unsigned int	num_dup;

	out = 1;
	num_dup = num;
	if (num_dup / 16 != 0)
		out += ft_puthex_fd(num_dup / 16, iscap, fd);
	if (num_dup % 16 <= 9)
		ft_putchar_fd(num_dup % 16 + 48, fd);
	else
		ft_putchar_fd((num_dup % 16 + 87) - 32 * iscap, fd);
	return (out);
}

int	ft_putptr_fd(unsigned long num, int fd)
{
	int				out;
	unsigned long	num_dup;

	out = 1;
	num_dup = num;
	if (num_dup / 16 != 0)
		out += ft_putptr_fd(num_dup / 16, fd);
	if (num_dup % 16 <= 9)
		ft_putchar_fd(num_dup % 16 + 48, fd);
	else
		ft_putchar_fd((num_dup % 16 + 87), fd);
	return (out);
}

void	ft_putunbr_fd(unsigned int n, int fd)
{
	unsigned long	n_dup;

	n_dup = n;
	if (n_dup / 10 != 0)
		ft_putunbr_fd(n_dup / 10, fd);
	ft_putchar_fd(n_dup % 10 + 48, fd);
}
