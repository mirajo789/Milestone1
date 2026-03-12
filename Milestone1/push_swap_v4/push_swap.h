/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rirazafi <rirazafi@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 07:07:07 by rirazafi          #+#    #+#             */
/*   Updated: 2026/03/12 10:25:53 by rirazafi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos_in_a;
	int				cost_a;
	int				cost_b;
	int				total_cost;
	int				chunk_id;
	int				is_cheapest;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct s_bench
{
	double			disorder;
	char			*strategy;
	char			*algo;
	int				totale_ops;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_bench;

// ========== init_stack.c ==========
t_stack	*create_stack(int value);
void	add_to_stack(t_stack **stack, int value);
void	free_stack(t_stack *stack);

// ========== main_parser.c ==========
long	ft_atol(char *nptr);
int		is_valid_int(char *nptr);
int		is_overflow(char *nptr);
void	ft_putstr_fd(char *s, int fd);
int		ft_strcmp(char *s1, char *s2);

// ========== main.c ==========

// ========== set_fields_stack_1.c ==========
void	set_indexes(t_stack *stack);
void	set_pos_in_a(t_stack *a, t_stack *b);
void	set_cost_b(t_stack *b);
void	set_cost_a(t_stack *a, t_stack *b);

// ========== set_fields_stack_2.c ==========
void	set_total_cost(t_stack *b);
int		get_abs(int nbr);
void	set_cheapest(t_stack *b);
void	set_chunk_id(t_stack *a, int chunk_size);
void	set_fields_stack(t_stack *a, t_stack *b);

// ========== get_fields_stack.c ==========
int		get_stack_size(t_stack *stack);
t_stack	*get_cheapest(t_stack *b);
int		get_min_pos(t_stack *a);
int		get_max_index(t_stack *stack);
int		get_pos(t_stack *stack, int index);

// ========== ops_swap.c ==========
void	sa(t_stack **a, t_bench *bench);
void	sb(t_stack **b, t_bench *bench);
void	ss(t_stack **a, t_stack **b, t_bench *bench);

// ========== ops_push.c ==========
void	pa(t_stack **a, t_stack **b, t_bench *bench);
void	pb(t_stack **b, t_stack **a, t_bench *bench);

// ========== ops_rotate.c ==========
void	ra(t_stack **a, t_bench *bench);
void	rb(t_stack **b, t_bench *bench);
void	rr(t_stack **a, t_stack **b, t_bench *bench);

// ========== ops_rrotate.c ==========
void	rra(t_stack **a, t_bench *bench);
void	rrb(t_stack **b, t_bench *bench);
void	rrr(t_stack **a, t_stack **b, t_bench *bench);

// ========== move_cheapest.c ==========
void	do_rr(t_stack **a, t_stack **b, t_stack *cheapest, t_bench *bench);
void	do_rrr(t_stack **a, t_stack **b, t_stack *cheapest, t_bench *bench);
void	do_ra_rrb(t_stack **a, t_stack **b, t_stack *cheapest, t_bench *bench);
void	do_rra_rb(t_stack **a, t_stack **b, t_stack *cheapest, t_bench *bench);
void	move_cheapest(t_stack **a, t_stack **b, t_bench *bench);

// ========== algo_selector.c ==========
double	compute_disorder(t_stack *a);
int		is_sorted(t_stack *a);
void	sort_adaptive(t_stack **a, t_stack **b, t_bench *bench);

// ========== sort_small.c ==========
void	sort_small(t_stack **a, t_bench *bench);

// ========== sort_insertion.c ==========
void	final_rotation(t_stack **a, t_bench *bench);
void	sort_insertion(t_stack **a, t_stack **b, t_bench *bench);

// ========== sort_radix_lsd.c ==========
void	sort_radix_lsd(t_stack **a, t_stack **b, t_bench *bench);

// ========== sort_chunk_utils.c ==========
int		get_sqrt(int n);
int		get_chunk_size(int size);
int		get_median_chunk(t_stack *a, int chunk_id);
int		get_max_index_chunk(t_stack *a, int chunk_id);
void	do_rb_rrb(t_stack **b, int pos, t_bench *bench);
void	do_ra_rra(t_stack **a, int pos, t_bench *bench);

// ========== sort_chunk.c ==========
void	push_chunk_to_b(t_stack **a, t_stack **b, int id, t_bench *bench);
void	set_max_to_top(t_stack **b, int max_index, t_bench *bench);
void	sort_chunk(t_stack **a, t_stack **b, t_bench *bench);

// ========== bench.c ==========
void	init_bench(t_bench *bench);
void	init_strategy(t_bench *bench, char *strategy, char *algo);
void	count_ops(t_bench *bench, char *op);
void	count_total_ops(t_bench *bench);
void	print_bench(t_bench *bench);

// ========== stderr_print.c ==========
void	print_error_and_exit(void);
void	stderr_str(char *str);
void	stderr_nbr(int nbr);
void	stderr_disorder(t_bench *bench);
void	stderr_strategy(t_bench *bench);
void	stderr_totale_ops(t_bench *bench);
void	stderr_ops_count(t_bench *bench);

#endif
