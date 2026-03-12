/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 08:33:30 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 09:51:55 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **a, t_stack **b, t_bench *bench)
{
	t_stack	*tmp;

	if (!*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	tmp->next = *a;
	tmp->prev = NULL;
	if (*a)
		(*a)->prev = tmp;
	*a = tmp;
	count_ops(bench, "pa");
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack **b, t_stack **a, t_bench *bench)
{
	t_stack	*tmp;

	if (!*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	tmp->next = *b;
	tmp->prev = NULL;
	if (*b)
		(*b)->prev = tmp;
	*b = tmp;
	count_ops(bench, "pb");
	ft_putstr_fd("pb\n", 1);
}
