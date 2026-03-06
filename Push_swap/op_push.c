/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 10:20:30 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:32:00 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_stack **a, t_stack **b)
{
	t_stack *tmp;
	
	if (!(*b))
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write (1, "pa\n", 3);
}

void pb(t_stack **b, t_stack **a)
{
	t_stack *tmp;
	
	if (!(*a))
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write (1, "pb\n", 3);
}