/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 15:45:20 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 11:22:14 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*new_stack(int	value)
{
	t_stack *new;

	new = (t_stack *) malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = -1;
	new->next = NULL;
	return (new);
}

void	push_back(t_stack **stack, int value)
{
	t_stack *tmp;
	t_stack *new_node;

	new_node = new_stack(value);
	if (*stack == NULL)
	{
		*stack = new_node;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->value == value)
		{
			write (2, "Error\n", 6);
			exit(1);
		}
		tmp = tmp->next;
	}
	if (tmp->value == value)
	{
		write (2, "Error\n", 6);
		exit(1);
	}
	tmp->next = new_node;
}