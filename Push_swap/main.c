/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 09:08:28 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 23:03:35 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// static void    print_stack(t_stack *a)
// {
//     while (a)
//     {
//         printf("[%d] -> ", a->value);
//         a = a->next;
//     }
//     printf("(null)\n");
// }

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
	int		i;

	a = NULL;
	b = NULL;
	i = 1;
	while (argc > i)
	{
		if (!is_valid_int(argv[i]) || (is_overflow(ft_atol(argv[i]))))
		{
			write(2,"Error\n", 6);
			exit(1);
		}
		else
			push_back(&a, ft_atol(argv[i]));
		i++;
	}
	set_index(a);
	algo_selector(&a, &b);
	
	//print_stack(a);
	return (0);
}