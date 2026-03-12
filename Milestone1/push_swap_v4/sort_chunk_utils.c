/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 10:13:19 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 09:59:50 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_sqrt(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

int	get_chunk_size(int size)
{
	int	base;

	base = get_sqrt(size);
	if (size <= 100)
		return (base);
	return (base * 3 / 2);
}

int	get_median_chunk(t_stack *a, int chunk_id)
{
	int	min;
	int	max;

	min = INT_MAX;
	max = -1;
	while (a)
	{
		if (a->chunk_id == chunk_id)
		{
			if (a->index < min)
				min = a->index;
			if (a->index > max)
				max = a->index;
		}
		a = a->next;
	}
	return ((min + max) / 2);
}

int	get_max_index_chunk(t_stack *a, int chunk_id)
{
	int	max;

	max = -1;
	while (a)
	{
		if (a->chunk_id == chunk_id && a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

void	do_rb_rrb(t_stack **b, int pos, t_bench *bench)
{
	int	rotate;
	int	size;

	size = get_stack_size(*b);
	if (pos <= size / 2)
	{
		rotate = pos;
		while (rotate--)
			rb(b, bench);
	}
	else
	{
		rotate = size - pos;
		while (rotate--)
			rrb(b, bench);
	}
}
