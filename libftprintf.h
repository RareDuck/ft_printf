/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayague-a <ayague-a@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 21:11:24 by ayague-a          #+#    #+#             */
/*   Updated: 2026/10/06 11:46:14 by ayague-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdint.h>

// ft_printf
int		ft_printf(char const *format, ...);

// Flag managers
void	flag_manager(char **ptr, int *out, va_list args);

// Formatters
void	format_c(char **ptr, int *out, va_list args);
void	format_s(char **ptr, int *out, va_list args);
void	format_p(char **ptr, int *out, va_list args);
void	format_i(char **ptr, int *out, va_list args);
void	format_u(char **ptr, int *out, va_list args);
void	format_x(char **ptr, int *out, va_list args);
void	format_xx(char **ptr, int *out, va_list args);
void	format_double(char **ptr, int *out);

// Utils
int		ft_puthex_fd(unsigned int num, int iscap, int fd);
int		ft_putptr_fd(unsigned long num, int fd);
void	ft_putunbr_fd(unsigned int n, int fd);