/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 09:00:34 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 09:54:05 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **a, t_bench *bench)
{
	t_stack	*tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	tmp->next = (*a)->next;
	if ((*a)->next)
		(*a)->next->prev = tmp;
	(*a)->next = tmp;
	tmp->prev = *a;
	count_ops(bench, "sa");
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = tmp;
	(*b)->next = tmp;
	tmp->prev = *b;
	count_ops(bench, "sb");
	ft_putstr_fd("sb\n", 1);
}

static void	sa_np(t_stack **a)
{
	int	tmp;

	if (!*a || !(*a)->next)
		return ;
	tmp = (*a)->value;
	(*a)->value = (*a)->next->value;
	(*a)->next->value = tmp;
	tmp = (*a)->index;
	(*a)->index = (*a)->next->index;
	(*a)->next->index = tmp;
}

static void	sb_np(t_stack **b)
{
	t_stack	*tmp;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	tmp->next = (*b)->next;
	if ((*b)->next)
		(*b)->next->prev = tmp;
	(*b)->next = tmp;
	tmp->prev = *b;
}

void	ss(t_stack **a, t_stack **b, t_bench *bench)
{
	sa_np(a);
	sb_np(b);
	count_ops(bench, "ss");
	ft_putstr_fd("ss\n", 1);
}
