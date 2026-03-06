/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:57:00 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:16:02 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *nptr)
{
	int		i;
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}

int	is_valid_int(char *nptr)
{
	int i;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (nptr[i] < '0' || nptr[i] > '9')
		return (0);
	while (nptr[i] >= '0' && nptr[i] <= '9')
		i++;
	if (nptr[i] != '\0')
		return (0);
	return (1);
}

int	is_overflow(long nbr)
{
	if (nbr > 2147483647 || nbr < -2147483648)
		return (1);
	return (0);
}