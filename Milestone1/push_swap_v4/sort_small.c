/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:52:14 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:15:54 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_stack **stack, t_bench *bench)
{
	int	first;
	int	second;

	if (!*stack || !(*stack)->next)
		return ;
	first = (*stack)->index;
	second = (*stack)->next->index;
	if (first > second)
		sa(stack, bench);
	return ;
}

static void	sort_three(t_stack **stack, t_bench *bench)
{
	int	first;
	int	second;
	int	third;

	if (!*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = (*stack)->index;
	second = (*stack)->next->index;
	third = (*stack)->next->next->index;
	if (first < second && second > third && first < third)
	{
		sa(stack, bench);
		ra(stack, bench);
	}
	else if (first > second && second < third && first < third)
		sa(stack, bench);
	else if (first > second && second > third && first > third)
	{
		sa(stack, bench);
		rra(stack, bench);
	}
	else if (first > second && second < third && first > third)
		ra(stack, bench);
	else if (first < second && second > third && first > third)
		rra(stack, bench);
}

void	sort_small(t_stack	**a, t_bench *bench)
{
	int	size;

	size = get_stack_size(*a);
	if (size == 2)
		sort_two(a, bench);
	else if (size == 3)
		sort_three(a, bench);
	return ;
}
