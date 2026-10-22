/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 10:56:22 by ayague-a          #+#    #+#             */
/*   Updated: 2026/10/03 03:56:24 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flag_manager(char **ptr, int *out, va_list args)
{
	(*ptr)++;
	if (**ptr == 'c')
		format_c(ptr, out, args);
	else if (**ptr == 's')
		format_s(ptr, out, args);
	else if (**ptr == 'p')
		format_p(ptr, out, args);
	else if (**ptr == 'd' || **ptr == 'i')
		format_i(ptr, out, args);
	else if (**ptr == 'u')
		format_u(ptr, out, args);
	else if (**ptr == 'x')
		format_x(ptr, out, args);
	else if (**ptr == 'X')
		format_xx(ptr, out, args);
	else if (**ptr == '%')
		format_double(ptr, out);
}
