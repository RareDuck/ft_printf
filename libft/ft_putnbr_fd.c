/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/26 12:45:55 by NEMO              #+#    #+#             */
/*   Updated: 2026/09/25 14:57:15 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	n_dup;

	n_dup = n;
	if (n_dup < 0)
	{
		ft_putchar_fd('-', fd);
		n_dup *= -1;
	}
	if (n_dup / 10 != 0)
		ft_putnbr_fd(n_dup / 10, fd);
	ft_putchar_fd(n_dup % 10 + 48, fd);
}
