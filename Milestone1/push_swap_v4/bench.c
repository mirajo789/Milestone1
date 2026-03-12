/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 07:43:10 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:29:16 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_bench(t_bench *bench)
{
	bench->disorder = 0.0;
	bench->totale_ops = 0;
	bench->strategy = NULL;
	bench->algo = NULL;
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
}

void	init_strategy(t_bench *bench, char *strategy, char *algo)
{
	bench->strategy = strategy;
	bench->algo = algo;
}

void	count_ops(t_bench *bench, char *op)
{
	if (ft_strcmp(op, "sa") == 0)
		bench->sa++;
	else if (ft_strcmp(op, "sb") == 0)
		bench->sb++;
	else if (ft_strcmp(op, "ss") == 0)
		bench->ss++;
	else if (ft_strcmp(op, "pa") == 0)
		bench->pa++;
	else if (ft_strcmp(op, "pb") == 0)
		bench->pb++;
	else if (ft_strcmp(op, "ra") == 0)
		bench->ra++;
	else if (ft_strcmp(op, "rb") == 0)
		bench->rb++;
	else if (ft_strcmp(op, "rr") == 0)
		bench->rr++;
	else if (ft_strcmp(op, "rra") == 0)
		bench->rra++;
	else if (ft_strcmp(op, "rrb") == 0)
		bench->rrb++;
	else if (ft_strcmp(op, "rrr") == 0)
		bench->rrr++;
}

void	count_total_ops(t_bench *bench)
{
	bench->totale_ops = bench->sa;
	bench->totale_ops += bench->sb;
	bench->totale_ops += bench->ss;
	bench->totale_ops += bench->pa;
	bench->totale_ops += bench->pb;
	bench->totale_ops += bench->ra;
	bench->totale_ops += bench->rb;
	bench->totale_ops += bench->rr;
	bench->totale_ops += bench->rra;
	bench->totale_ops += bench->rrb;
	bench->totale_ops += bench->rrr;
}

void	print_bench(t_bench *bench)
{
	stderr_disorder(bench);
	stderr_strategy(bench);
	count_total_ops(bench);
	stderr_totale_ops(bench);
	stderr_ops_count(bench);
}
