/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_selector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:01:32 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:40:12 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_selector(t_stack **a, t_stack **b)
{
	int		size;
	double	disordre;

	size = get_size_stack(*a);
	disordre = compute_disorder(*a);
	printf("disordre = %f\n", disordre);
	if (get_size_stack(*a) <= 3)
		sort_small(a);
	else
		sort_insertion(a, b);
	return ;
}