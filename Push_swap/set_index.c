/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:59:33 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 11:36:17 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void set_index(t_stack *a)
{
	t_stack *tmp;
	t_stack *smallest;
	int index;
	
	if (!a)
		return ;
	index = 0;
	while (1)
	{
		tmp = a;
		smallest = NULL;
		while (tmp)
		{
			if (tmp->index == -1)
			{
				if ((!smallest || tmp->value < smallest->value))
					smallest = tmp;
			}
			tmp = tmp->next;
		}
		if (smallest == NULL)
			break ;
		smallest->index = index;
		index++;
	}
}