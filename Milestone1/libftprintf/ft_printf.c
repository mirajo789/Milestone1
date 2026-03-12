/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:06:32 by mirajora          #+#    #+#             */
/*   Updated: 2026/02/21 13:54:46 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_checker(char type, va_list args)
{
	if (type == 'x' || type == 'X')
		return (ft_hex(va_arg(args, unsigned int), type));
	if (type == 'i' || type == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (type == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	if (type == 'p')
		return (ft_mem_hex(va_arg(args, void *)));
	if (type == '%')
		return (ft_putchar('%'));
	write(1, "%", 1);
	write(1, &type, 1);
	return (2);
}

static int	ft_vprintf(const char *format, va_list args)
{
	int	count;
	int	i;
	int	res;

	count = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			res = ft_checker(format[i + 1], args);
			if (res == -1)
				return (-1);
			count += res;
			i++;
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	if (!format)
		return (-1);
	va_start(args, format);
	ret = ft_vprintf(format, args);
	va_end(args);
	return (ret);
}
#include <stdio.h>

int main()
{
	ft_printf("kello% \n");
	printf("kello% \n");
}
