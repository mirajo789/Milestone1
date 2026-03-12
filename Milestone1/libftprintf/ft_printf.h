/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 10:51:51 by mirajora          #+#    #+#             */
/*   Updated: 2026/02/14 15:35:36 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int			ft_putchar(char c);
int			ft_putstr(char *str);
int			ft_putnbr(long nb);
long long	ft_hex(unsigned long long n, int type);
int			ft_mem_hex(void *ptr);
int			ft_printf(const char *format, ...);
int			ft_checker(char type, va_list args);

#endif