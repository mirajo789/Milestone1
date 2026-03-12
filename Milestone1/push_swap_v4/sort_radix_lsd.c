/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix_lsd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:59:02 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:15:54 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	bits;

	bits = 0;
	while (((size -1) >> bits))
	{
		bits++;
	}
	return (bits);
}

void	sort_radix_lsd(t_stack **a, t_stack **b, t_bench *bench)
{
	int	size;
	int	max_bits;
	int	i;
	int	bit;

	size = get_stack_size(*a);
	max_bits = get_max_bits(size);
	bit = 0;
	while (bit < max_bits)
	{
		i = size;
		while (i--)
		{
			if (!(((*a)->index >> bit) & 1))
				pb(b, a, bench);
			else
				ra(a, bench);
		}
		while (*b)
			pa(a, b, bench);
		bit++;
	}
	return ;
}
