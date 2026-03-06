/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_insertion_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:56:12 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:33:41 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int get_min_pos(t_stack **b)
{
	t_stack *tmp;
	int pos;
	int min[2];

	tmp = *b;
	min[0] = INT_MAX;
	min[1] = 0;
	pos = 0;
	while (tmp)
	{
		if (tmp->index < min[0])
		{
			min[1] = pos;
			min[0] = tmp->index;
		}
		pos++;
		tmp = tmp->next;
	}
	return (min[1]);
}

int find_pos_b(t_stack **b, int value)
{
	t_stack *tmp;
	int pos;
	int best[2];
	
	best[0] = -1;
	best[1] = 0;
	tmp = *b;
	pos = 0;

	while (tmp)
	{
		if (tmp->index > best[0] && tmp->index < value)
		{
			best[1] = pos;
			best[0] = tmp->index;
		}
		pos++;
		tmp = tmp->next;
	}
	if (best[0] == -1)
		return (get_min_pos(b));
	return (best[1]);
}

int find_index_pos(t_stack *a, int target_index)
{
	t_stack *tmp;
	int pos;
	
	pos = 0;
	tmp = a;
	while (tmp)
	{
		if (tmp->index == target_index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (0);
}
