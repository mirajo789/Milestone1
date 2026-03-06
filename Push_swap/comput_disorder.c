/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comput_disorder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:13:29 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/05 12:00:50 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double compute_disorder(t_stack *stack_a)
{
	double mistakes;
	int total_pairs;
	t_stack *current;
	t_stack *runner;

	mistakes = 0;
	total_pairs = 0;
	current = stack_a;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			total_pairs++;
			if (current->value > runner->value)
				mistakes++;
			runner = runner->next;
		}
		current = current->next;
	}
	if (total_pairs == 0)
		return (0.0);
	return (mistakes / total_pairs);
}