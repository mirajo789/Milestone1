/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 08:41:06 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:58:34 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_stack	*i;
	t_stack	*j;
	double	mistakes;
	int		totale_pairs;

	i = a;
	mistakes = 0;
	totale_pairs = 0;
	while (i)
	{
		j = i->next;
		while (j)
		{
			totale_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (totale_pairs == 0)
		return (0.0);
	return (mistakes / totale_pairs);
}

int	is_sorted(t_stack *a)
{
	while (a && a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

void	sort_adaptive(t_stack	**a, t_stack **b, t_bench *bench)
{
	double	disorder;
	int		size;

	size = get_stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	disorder = compute_disorder(*a);
	if (disorder < 0.2)
	{
		init_strategy(bench, "adaptive", " / O(n²)");
		sort_insertion(a, b, bench);
	}
	else if (0.2 <= disorder && disorder < 0.5)
	{
		init_strategy(bench, "adaptive", " / O(n√n)");
		sort_chunk(a, b, bench);
	}
	else
	{
		init_strategy(bench, "adaptive", " / O(n log n)");
		sort_radix_lsd(a, b, bench);
	}
}
