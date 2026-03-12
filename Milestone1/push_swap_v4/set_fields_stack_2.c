/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fields_stack_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:26:15 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/11 11:18:03 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_total_cost(t_stack *b)
{
	t_stack	*tmp;

	tmp = b;
	while (tmp)
	{
		tmp->total_cost = get_abs(tmp->cost_a) + get_abs(tmp->cost_b);
		tmp = tmp->next;
	}
}

int	get_abs(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	return (nbr);
}

void	set_cheapest(t_stack *b)
{
	t_stack	*tmp;
	int		min_cost;

	tmp = b;
	min_cost = INT_MAX;
	while (tmp)
	{
		if (tmp->total_cost < min_cost)
		{
			min_cost = get_abs(tmp->total_cost);
		}
		tmp = tmp->next;
	}
	tmp = b;
	while (tmp)
	{
		if (get_abs(tmp->total_cost) == min_cost)
			tmp->is_cheapest = 1;
		else
			tmp->is_cheapest = 0;
		tmp = tmp->next;
	}
}

void	set_chunk_id(t_stack *a, int chunk_size)
{
	while (a)
	{
		a->chunk_id = a->index / chunk_size;
		a = a->next;
	}
}

void	set_fields_stack(t_stack *a, t_stack *b)
{
	set_pos_in_a(a, b);
	set_cost_b(b);
	set_cost_a(a, b);
	set_total_cost(b);
	set_cheapest(b);
}
