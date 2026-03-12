/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 10:03:59 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 09:58:45 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack **a, t_bench *bench)
{
	t_stack	*tmp;
	t_stack	*tmp_a;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp_a = *a;
	tmp->next = NULL;
	while ((tmp_a->next))
		tmp_a = (tmp_a)->next;
	tmp_a->next = tmp;
	count_ops(bench, "ra");
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **b, t_bench *bench)
{
	t_stack	*tmp;
	t_stack	*tmp_b;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp_b = *b;
	tmp->next = NULL;
	while ((tmp_b->next))
		tmp_b = (tmp_b)->next;
	tmp_b->next = tmp;
	count_ops(bench, "rb");
	ft_putstr_fd("rb\n", 1);
}

static void	ra_np(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*tmp_a;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp_a = *a;
	tmp->next = NULL;
	while ((tmp_a->next))
		tmp_a = (tmp_a)->next;
	tmp_a->next = tmp;
}

static void	rb_np(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*tmp_b;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp_b = *b;
	tmp->next = NULL;
	while ((tmp_b->next))
		tmp_b = (tmp_b)->next;
	tmp_b->next = tmp;
}

void	rr(t_stack **a, t_stack **b, t_bench *bench)
{
	ra_np(a);
	rb_np(b);
	count_ops(bench, "rr");
	ft_putstr_fd("rr\n", 1);
}
