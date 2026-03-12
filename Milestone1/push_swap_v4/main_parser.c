/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 07:29:46 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:24:03 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *nptr)
{
	long	output;
	int		sign;
	int		i;

	output = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		output = (output * 10) + (nptr[i] - '0');
		i++;
	}
	return ((output * sign));
}

int	is_valid_int(char	*nptr)
{
	int	i;

	i = 0;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	if (!nptr[i])
		return (0);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(char *nptr)
{
	long	value;

	value = ft_atol(nptr);
	if (value > INT_MAX || value < INT_MIN)
		return (1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
