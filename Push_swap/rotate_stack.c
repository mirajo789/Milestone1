/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 12:43:07 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:52:39 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotate_a_to(t_stack **a, int pos)
{
	int size;

	size = get_size_stack(*a);
	if (pos <= size / 2)
		while (pos--)
			ra(a);
	else
		while (++pos <= size)
			rra(a);
}

void rotate_b_to(t_stack **b, int pos)
{
	int size;

	size = get_size_stack(*b);
	if (pos <= size / 2)
		while (pos--)
			rb(b);
	else
		while (++pos <= size)
			rrb(b);
}

