/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 07:10:44 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:15:54 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*create_stack(int value)
{
	t_stack	*new_stack;

	new_stack = (t_stack *)malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	new_stack->value = value;
	new_stack->index = -1;
	new_stack->pos_in_a = -1;
	new_stack->cost_a = 0;
	new_stack->cost_b = 0;
	new_stack->total_cost = 0;
	new_stack->chunk_id = -1;
	new_stack->is_cheapest = 0;
	new_stack->prev = NULL;
	new_stack->next = NULL;
	return (new_stack);
}

void	add_to_stack(t_stack **stack, int value)
{
	t_stack	*new_stack;
	t_stack	*tmp;
	t_stack	*prev;

	if (!*stack)
	{
		*stack = create_stack(value);
		return ;
	}
	tmp = *stack;
	while (tmp)
	{
		if (tmp->value == value)
			print_error_and_exit();
		prev = tmp;
		tmp = tmp->next;
	}
	new_stack = create_stack(value);
	if (!new_stack)
		print_error_and_exit();
	prev->next = new_stack;
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	tmp = NULL;
}

void	set_max_to_top(t_stack	**b, int max_index, t_bench *bench)
{
	int	pos;

	pos = get_pos(*b, max_index);
	do_rb_rrb(b, pos, bench);
}
