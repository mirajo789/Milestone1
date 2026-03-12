/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 09:21:11 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:15:54 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_ra_rra(t_stack **a, int pos, t_bench *bench)
{
	int	rotate;
	int	size;

	size = get_stack_size(*a);
	if (pos <= size / 2)
	{
		rotate = pos;
		while (rotate--)
			ra(a, bench);
	}
	else
	{
		rotate = size - pos;
		while (rotate--)
			rra(a, bench);
	}
}

static void	set_cost_chunk(t_stack *a, int chunk_id)
{
	int	pos;
	int	size;

	size = get_stack_size(a);
	pos = 0;
	while (a)
	{
		if (a->chunk_id == chunk_id)
		{
			if (pos <= size / 2)
				a->cost_a = pos;
			else
				a->cost_a = pos - size;
		}
		pos++;
		a = a->next;
	}
}

static t_stack	*get_cheapest_in_chunk(t_stack *a, int chunk_id)
{
	t_stack	*best;
	int		min_cost;

	min_cost = INT_MAX;
	best = NULL;
	while (a)
	{
		if (a->chunk_id == chunk_id)
		{
			if (get_abs(a->cost_a) < min_cost)
			{
				min_cost = get_abs(a->cost_a);
				best = a;
			}
		}
		a = a->next;
	}
	return (best);
}

void	push_chunk_to_b(t_stack **a, t_stack **b, int id, t_bench *bench)
{
	t_stack	*cheapest;
	int		median;

	median = get_median_chunk(*a, id);
	while (1)
	{
		set_cost_chunk(*a, id);
		cheapest = get_cheapest_in_chunk(*a, id);
		if (!cheapest)
			break ;
		do_ra_rra(a, get_pos(*a, cheapest->index), bench);
		pb(b, a, bench);
		if (cheapest->index <= median)
			rb(b, bench);
	}
}

void	sort_chunk(t_stack **a, t_stack **b, t_bench *bench)
{
	int	chunk_size;
	int	size_a;
	int	chunk_nb;
	int	chunk_id;
	int	max_index;

	size_a = get_stack_size(*a);
	chunk_size = get_chunk_size(size_a);
	set_chunk_id(*a, chunk_size);
	chunk_nb = (size_a / chunk_size + (size_a % chunk_size != 0));
	chunk_id = 0;
	while (chunk_id < chunk_nb)
	{
		push_chunk_to_b(a, b, chunk_id, bench);
		chunk_id++;
	}
	max_index = size_a - 1;
	while (*b)
	{
		set_max_to_top(b, max_index, bench);
		pa(a, b, bench);
		max_index--;
	}
}
