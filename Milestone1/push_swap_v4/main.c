/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 09:18:28 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:58:25 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_mode(char *s)
{
	if (ft_strcmp(s, "--bench") == 0)
		return (5);
	if (ft_strcmp(s, "--simple") == 0)
		return (1);
	if (ft_strcmp(s, "--medium") == 0)
		return (2);
	if (ft_strcmp(s, "--complex") == 0)
		return (3);
	if (ft_strcmp(s, "--adaptive") == 0)
		return (0);
	ft_putstr_fd("Error\n", 2);
	exit(1);
	return (0);
}

static void	run_mode_sort(t_stack **a, t_stack **b, int mode, t_bench *bench)
{
	bench->disorder = compute_disorder(*a);
	if (mode == 1)
	{
		init_strategy(bench, "simple", " / O(n²)");
		sort_insertion(a, b, bench);
	}
	else if (mode == 2)
	{
		init_strategy(bench, "medium", " / O(n√n)");
		sort_chunk(a, b, bench);
	}
	else if (mode == 3)
	{
		init_strategy(bench, "complex", " / O(n log n)");
		sort_radix_lsd(a, b, bench);
	}
	else
		sort_adaptive(a, b, bench);
}

static void	run_sort(t_stack **a, t_stack **b, int mode, t_bench *bench)
{
	int	size;

	size = get_stack_size(*a);
	set_indexes(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size <= 3)
		sort_small(a, bench);
	else
		run_mode_sort(a, b, mode, bench);
}

static int	parse_and_fill(int ac, char **av, t_stack **a, int *mode)
{
	int	i;
	int	is_bench;

	i = 0;
	is_bench = 0;
	while (++i < ac)
	{
		if (av[1][0] == '-' && av[1][1] == '-')
			is_bench = get_mode(av[1]);
		if (av[i][0] == '-' && av[i][1] == '-')
			*mode = get_mode(av[i]);
		else if (!is_valid_int(av[i]) || is_overflow(av[i]))
		{
			free_stack(*a);
			print_error_and_exit();
		}
		else
			add_to_stack(a, ft_atol(av[i]));
	}
	return (is_bench);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_bench	bench;
	int		mode;
	int		is_bench;

	a = NULL;
	b = NULL;
	mode = 0;
	if (ac < 2)
		return (0);
	is_bench = parse_and_fill(ac, av, &a, &mode);
	if (is_bench == -1)
		print_error_and_exit();
	if (is_bench == 5)
	{
		init_bench(&bench);
		run_sort(&a, &b, mode, &bench);
		print_bench(&bench);
	}
	else
		run_sort(&a, &b, mode, &bench);
	return (free_stack(a), free_stack(b), 0);
}
