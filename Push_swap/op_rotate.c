/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 08:42:35 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:32:00 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ra(t_stack **a)
{
	t_stack *first;
	t_stack *tmp;
	
	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	write (1, "ra\n", 3);
}

void rb(t_stack **b)
{
	t_stack *first;
	t_stack *tmp;
	
	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	tmp = *b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	write (1, "rb\n", 3);
}

static void ra_r(t_stack **a)
{
	t_stack *first;
	t_stack *tmp;
	
	if (!*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
}

static void rb_r(t_stack **b)
{
	t_stack *first;
	t_stack *tmp;
	
	if (!*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	tmp = *b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
}

void rr(t_stack **a, t_stack **b)
{
	ra_r(a);
	rb_r(b);
	write (1, "rr\n", 3);
}