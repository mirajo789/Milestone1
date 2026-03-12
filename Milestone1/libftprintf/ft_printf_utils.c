/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 19:47:30 by mirajora          #+#    #+#             */
/*   Updated: 2026/02/19 14:40:43 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	if (str == NULL)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
		len++;
	}
	return (len);
}

int	ft_putnbr(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		if (ft_putchar('-') == -1)
			return (-1);
		nb = -nb;
		len++;
	}
	if (nb > 9)
	{
		len += ft_putnbr(nb / 10);
	}
	if (ft_putchar((nb % 10) + '0') == -1)
		return (-1);
	len++;
	return (len);
}

long long	ft_hex(unsigned long long n, int type)
{
	char	*base;
	int		len;

	len = 0;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n >= 16)
		len += ft_hex(n / 16, type);
	if (write(1, &base[n % 16], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_mem_hex(void *ptr)
{
	int	len;
	int	err;

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len = 0;
	err = 0;
	if (ft_putstr("0x") == -1)
		return (-1);
	err = ft_hex((unsigned long)ptr, 'x');
	if (err == -1)
		return (-1);
	len += err;
	return (len + 2);
}
