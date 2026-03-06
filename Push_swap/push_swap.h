/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirajora <mirajora@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:04:23 by mirajora          #+#    #+#             */
/*   Updated: 2026/03/06 13:00:46 by mirajora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>

typedef struct s_stack
{
	int		value;
	int		index;
	struct s_stack *next;
}			t_stack;	

// ---------------[Stack Utils]---------------------------
t_stack	*new_stack(int	value);
void	push_back(t_stack **stack, int value);

// ---------------[Get info Stack]------------------------
int		get_size_stack(t_stack *a);

// ---------------[Operation Stack]-----------------------
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **b, t_stack **a);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

// ---------------[Disordre]------------------------------
double	compute_disorder(t_stack *stack_a);

// ---------------[Main]----------------------------------
void	algo_selector(t_stack **a, t_stack **b);
long	ft_atol(const char *nptr);
int		is_valid_int(char *nptr);
int 	is_overflow(long nbr);

// ---------------[Tools]---------------------------------
void	set_index(t_stack *a);

// ---------------[Sort Small]----------------------------
void	sort_small(t_stack **a);

// ---------------[Sort Insertion Utils]------------------
int find_pos_b(t_stack **b, int value);
int find_index_pos(t_stack *a, int target_index);
// ---------------[Sort Insertion]------------------------
void sort_insertion(t_stack **a, t_stack **b);
// ---------------[rotate_stack]------------------------
void rotate_a_to(t_stack **a, int pos);
void rotate_b_to(t_stack **b, int pos);
#endif