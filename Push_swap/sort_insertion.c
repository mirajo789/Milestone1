/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 15:31:22 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:53:59 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int cost_to_top(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	return (size - pos);	
}

static int find_min_cost(t_stack **a, t_stack **b, int size_a, int size_b)
{
	t_stack *tmp;
	int pos;
	int cost;
	int best_pos;
	int best_cost;
	
	best_cost = INT_MAX;
	best_pos = 0;
	pos = 0;
	tmp = *a;
	while (tmp)
	{
		cost = cost_to_top(pos, size_a);
		cost += cost_to_top(find_pos_b(b, tmp->index), size_b);
		if (cost < best_cost)
		{
			best_pos = pos;
			best_cost = cost;
		}
		tmp = tmp->next;
		pos++;
	}
	return (best_pos);
}

void sort_insertion(t_stack **a, t_stack **b)
{
	int size_a;
	int size_b;
	int min_cost_pos;
	int pos_b;
	
	size_a = get_size_stack(*a);
	size_b = 0;
	while (size_a > 0)
	{
		min_cost_pos = find_min_cost(a, b, size_a, size_b);
		rotate_a_to(a, min_cost_pos);
		pos_b = find_pos_b(b, (*a)->index);
		rotate_b_to(b, pos_b);
		pb(b, a);
		size_a--;
		size_b++;
	}
	while (*b)
		pa(a, b);
	rotate_a_to(a, find_index_pos(*a, 0));
}
