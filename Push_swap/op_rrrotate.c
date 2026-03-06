/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rrrotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:36:12 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:04:56 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp2;
	t_stack *last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	tmp2 = *a;
	*a = last;
	(*a)->next = tmp2;
	write (1, "rra\n", 4);
}

void rrb(t_stack **b)
{
	t_stack *tmp;
	t_stack *tmp2;
	t_stack *last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	tmp2 = *b;
	*b = last;
	(*b)->next = tmp2;
	write (1, "rrb\n", 4);
}

static void rra_r(t_stack **a)
{
	t_stack *tmp;
	t_stack *tmp2;
	t_stack *last;

	if (!*a || !(*a)->next)
		return ;
	tmp = *a;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	tmp2 = *a;
	*a = last;
	(*a)->next = tmp2;
}

static void rrb_r(t_stack **b)
{
	t_stack *tmp;
	t_stack *tmp2;
	t_stack *last;

	if (!*b || !(*b)->next)
		return ;
	tmp = *b;
	while (tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	tmp2 = *b;
	*b = last;
	(*b)->next = tmp2;
}

void rrr(t_stack **a, t_stack **b)
{
	rra_r(a);
	rrb_r(b);
	write (1, "rrr\n", 4);
}