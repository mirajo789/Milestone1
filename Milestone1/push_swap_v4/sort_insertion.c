/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 10:37:27 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:15:54 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	final_rotation(t_stack **a, t_bench *bench)
{
	int	min_pos;
	int	size;
	int	rotation;

	min_pos = get_min_pos(*a);
	size = get_stack_size(*a);
	if (min_pos <= size / 2)
	{
		rotation = min_pos;
		while (rotation--)
			ra(a, bench);
	}
	else
	{
		rotation = size - min_pos;
		while (rotation--)
			rra(a, bench);
	}
	return ;
}

void	sort_insertion(t_stack **a, t_stack **b, t_bench *bench)
{
	while (get_stack_size(*a) > 3)
		pb(b, a, bench);
	sort_small(a, bench);
	while (*b)
	{
		set_fields_stack(*a, *b);
		move_cheapest(a, b, bench);
	}
	if (!is_sorted(*a))
		final_rotation(a, bench);
}
