/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:59:24 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:05:37 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_stack **a)
{
	int 	first;
	int		second;

	if (!*a || !(*a)->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;

	(*a)->next->value = first;
	(*a)->value = second;
	write (1, "sa\n", 3);
}

void sb(t_stack **b)
{
	int 	first;
	int		second;

	if (!*b || !(*b)->next)
		return ;
	first = (*b)->value;
	second = (*b)->next->value;

	(*b)->next->value = first;
	(*b)->value = second;
	write (1, "sb\n", 3);
}

static void sa_s(t_stack **a)
{
	int 	first;
	int		second;

	if (!*a || !(*a)->next)
		return ;
	first = (*a)->value;
	second = (*a)->next->value;

	(*a)->next->value = first;
	(*a)->value = second;
}

static void sb_s(t_stack **b)
{
	int 	first;
	int		second;

	if (!*b || !(*b)->next)
		return ;
	first = (*b)->value;
	second = (*b)->next->value;

	(*b)->next->value = first;
	(*b)->value = second;
}

void ss(t_stack **a, t_stack **b)
{
	sa_s(a);
	sb_s(b);
	write (1, "ss\n", 3);
}