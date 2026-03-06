/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:24:56 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:38:02 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_two(t_stack **stack)
{
	int first;
	int second;
	
	first = (*stack)->value;
	second = (*stack)->next->value;

	if (first > second)
		sa(stack);
}

static void sort_three(t_stack **stack)
{
	int first;
	int second;
	int third;

	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && second < third && first > third)
		ra(stack);
	else if (first > second && second > third && first > third)
	{
		sa(stack);
		rra(stack);
	}
	else if (first < second && second > third && first < third)
	{
		sa(stack);
		ra(stack);
	}
	else if (first < second && second > third && first > third)
		rra(stack);
	else if (first > second && second < third && first < third)
		sa(stack);
}

void sort_small(t_stack **a)
{
	if (get_size_stack(*a) == 2)
		sort_two(a);
	else if (get_size_stack(*a) == 3)
		sort_three(a);
}