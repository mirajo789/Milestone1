/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fields_stack_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 07:23:45 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/10 13:52:23 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_indexes(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;
	int		rank;

	current = stack;
	while (current)
	{
		tmp = stack;
		rank = 0;
		while (tmp)
		{
			if (tmp->value < current->value)
				rank++;
			tmp = tmp->next;
		}
		current->index = rank;
		current = current->next;
	}
}

static void	wrappe_arround(t_stack *a, t_stack *tmp_b)
{
	t_stack	*tmp_a;
	int		min_index;

	tmp_a = a;
	min_index = INT_MAX;
	while (tmp_a)
	{
		if (tmp_a->index < min_index)
			min_index = tmp_a->index;
		tmp_a = tmp_a->next;
	}
	tmp_b->pos_in_a = min_index;
}

void	set_pos_in_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		min_index;

	tmp_b = b;
	while (tmp_b)
	{
		min_index = INT_MAX;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->index > tmp_b->index && tmp_a->index < min_index)
			{
				min_index = tmp_a->index;
				tmp_b->pos_in_a = tmp_a->index;
			}
			tmp_a = tmp_a->next;
		}
		if (min_index == INT_MAX)
		{
			wrappe_arround(a, tmp_b);
		}
		tmp_b = tmp_b->next;
	}
}

void	set_cost_b(t_stack *b)
{
	t_stack	*tmp;
	int		size_b;
	int		pos;

	tmp = b;
	pos = 0;
	size_b = get_stack_size(b);
	while (tmp)
	{
		if (pos <= size_b / 2)
			tmp->cost_b = pos;
		else if (pos > size_b / 2)
			tmp->cost_b = pos - size_b;
		pos++;
		tmp = tmp->next;
	}
}

void	set_cost_a(t_stack *a, t_stack *b)
{
	t_stack	*tmp_b;
	t_stack	*tmp_a;
	int		pos;
	int		size_a;

	tmp_b = b;
	size_a = get_stack_size(a);
	while (tmp_b)
	{
		pos = 0;
		tmp_a = a;
		while (tmp_a)
		{
			if (tmp_a->index == tmp_b->pos_in_a)
			{
				if (pos <= size_a / 2)
					tmp_b->cost_a = pos;
				else
					tmp_b->cost_a = pos - size_a;
			}
			pos++;
			tmp_a = tmp_a->next;
		}
		tmp_b = tmp_b->next;
	}
}
