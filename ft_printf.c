/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 10:50:12 by ayague-a          #+#    #+#             */
/*   Updated: 2026/10/05 18:31:24 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *format, ...)
{
	va_list	args;
	char	*ptr;
	int		out;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	ptr = (char *)format;
	out = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '%')
			flag_manager(&ptr, &out, args);
		else
		{
			ft_putchar_fd(*ptr, 1);
			ptr++;
			out++;
		}
	}
	va_end(args);
	return (out);
}
