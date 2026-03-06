/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sort_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:01:22 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/04 13:16:04 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int get_size_stack(t_stack *a)
{
	int size;

	size = 0; 
	while (a)
	{
		size++;
		a = a->next;
	}
	return (size);
}