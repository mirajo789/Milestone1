/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_fields_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 08:57:21 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/11 10:15:59 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

t_stack	*get_cheapest(t_stack *b)
{
	while (b)
	{
		if (b->is_cheapest == 1)
			return (b);
		b = b->next;
	}
	return (NULL);
}

int	get_min_pos(t_stack *a)
{
	int	pos;
	int	min_pos;

	pos = 0;
	min_pos = 0;
	while (a)
	{
		if (a->index == 0)
			min_pos = pos;
		pos++;
		a = a->next;
	}
	return (min_pos);
}

int	get_max_index(t_stack *stack)
{
	int		max_index;
	t_stack	*tmp;

	max_index = 0;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > max_index)
			max_index = tmp->index;
		tmp = tmp->next;
	}
	return (max_index);
}

int	get_pos(t_stack *stack, int index)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index == index)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}
