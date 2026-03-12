/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_stderr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:34:20 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:33:06 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stderr_disorder(t_bench *bench)
{
	int	percentage;
	int	decimal;

	percentage = (int)(bench->disorder * 100);
	decimal = (int)(bench->disorder * 10000) % 100;
	stderr_str("[bench] Disorder: ");
	stderr_nbr(percentage);
	stderr_str(".");
	stderr_nbr(decimal);
	stderr_str("%\n");
}

void	stderr_strategy(t_bench *bench)
{
	stderr_str("[bench] Strategy: ");
	stderr_str(bench->strategy);
	stderr_str(bench->algo);
	stderr_str("\n");
}

void	stderr_totale_ops(t_bench *bench)
{
	stderr_str("[bench] Total_ops: ");
	stderr_nbr(bench->totale_ops);
	stderr_str("\n");
}

void	stderr_ops_count(t_bench *bench)
{
	stderr_str("[bench] sa: ");
	stderr_nbr(bench->sa);
	stderr_str(" sb: ");
	stderr_nbr(bench->sb);
	stderr_str(" ss: ");
	stderr_nbr(bench->ss);
	stderr_str(" pa: ");
	stderr_nbr(bench->pa);
	stderr_str(" pb: ");
	stderr_nbr(bench->pb);
	stderr_str("\n[bench] ra: ");
	stderr_nbr(bench->ra);
	stderr_str(" rb: ");
	stderr_nbr(bench->rb);
	stderr_str(" rr: ");
	stderr_nbr(bench->rr);
	stderr_str(" rra: ");
	stderr_nbr(bench->rra);
	stderr_str(" rrb: ");
	stderr_nbr(bench->rrb);
	stderr_str(" rrr: ");
	stderr_nbr(bench->rrr);
	stderr_str("\n");
}
