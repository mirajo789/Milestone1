/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cheapest.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 09:55:58 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:15:54 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 1. cost_a > 0 && cost_b > 0  → rr  jusqu'à ce que l'un des deux = 0
void	do_rr(t_stack **a, t_stack **b, t_stack *cheapest, t_bench *bench)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(a, b, bench);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
}

// 2. cost_a < 0 && cost_b < 0  → rrr jusqu'à ce que l'un des deux = 0
void	do_rrr(t_stack **a, t_stack **b, t_stack *cheapest, t_bench *bench)
{
	while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
	{
		rrr(a, b, bench);
		cheapest->cost_a++;
		cheapest->cost_b++;
	}
}

// 3. cost_a > 0 && cost_b < 0  → ra  et rrb séparément
void	do_ra_rrb(t_stack **a, t_stack **b, t_stack *cheapest, t_bench *bench)
{
	while (cheapest->cost_a > 0)
	{
		ra(a, bench);
		cheapest->cost_a--;
	}
	while (cheapest->cost_b < 0)
	{
		rrb(b, bench);
		cheapest->cost_b++;
	}
}

// 4. cost_a < 0 && cost_b > 0  → rra et rb  séparément
void	do_rra_rb(t_stack **a, t_stack **b, t_stack *cheapest, t_bench *bench)
{
	while (cheapest->cost_a < 0)
	{
		rra(a, bench);
		cheapest->cost_a++;
	}
	while (cheapest->cost_b > 0)
	{
		rb(b, bench);
		cheapest->cost_b--;
	}
}

void	move_cheapest(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*cheapest;

	cheapest = get_cheapest(*b);
	do_rr(a, b, cheapest, bench);
	do_rrr(a, b, cheapest, bench);
	do_ra_rrb(a, b, cheapest, bench);
	do_rra_rb(a, b, cheapest, bench);
	pa(a, b, bench);
}
