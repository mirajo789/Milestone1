/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 11:03:10 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 09:53:36 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **a, t_bench *bench)
{
	t_stack	*tmp;
	t_stack	*tmp_a;

	if (!*a || !(*a)->next)
		return ;
	tmp_a = *a;
	while ((tmp_a->next->next))
	{
		tmp_a = tmp_a->next;
	}
	tmp = tmp_a->next;
	tmp_a->next = NULL;
	tmp->next = *a;
	*a = tmp;
	count_ops(bench, "rra");
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **b, t_bench *bench)
{
	t_stack	*tmp;
	t_stack	*tmp_b;

	if (!*b || !(*b)->next)
		return ;
	tmp_b = *b;
	while ((tmp_b->next->next))
	{
		tmp_b = tmp_b->next;
	}
	tmp = tmp_b->next;
	tmp_b->next = NULL;
	tmp->next = *b;
	*b = tmp;
	count_ops(bench, "rrb");
	ft_putstr_fd("rrb\n", 1);
}

static void	rra_np(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp_a;

	if (!*a || !(*a)->next)
		return ;
	tmp_a = *a;
	while ((tmp_a->next->next))
	{
		tmp_a = tmp_a->next;
	}
	tmp = tmp_a->next;
	tmp_a->next = NULL;
	tmp->next = *a;
	*a = tmp;
}

static void	rrb_np(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_b;

	if (!*b || !(*b)->next)
		return ;
	tmp_b = *b;
	while ((tmp_b->next->next))
	{
		tmp_b = tmp_b->next;
	}
	tmp = tmp_b->next;
	tmp_b->next = NULL;
	tmp->next = *b;
	*b = tmp;
}

void	rrr(t_stack **a, t_stack **b, t_bench *bench)
{
	rra_np(a);
	rrb_np(b);
	count_ops(bench, "rrr");
	ft_putstr_fd("rrr\n", 1);
}
