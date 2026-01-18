/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:19:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/18 23:14:13 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# if BRUTEFORCE < 0
#  undef BRUTEFORCE
#  define BRUTEFORCE 0
# endif

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_bruteforce
{
	int		instructs[BRUTEFORCE + 2];
	int		instructs_size;
	void	*f_instructs[12];
	int		amount_to_sort;
	int		stack_size;
	int		smallest_index;
}	t_bf;

typedef struct s_algo
{
	int	curr_moves;
	int	min_moves;
	int	algo_nb;
	int	algo_param;
}	t_algo;

int		check_argssize(int ac, char **av);
int		*convert_to_arr(char **av, int argssize);
int		check_if_sorted(int *a, int a_size);
void	replace_value_with_index(int *a, int *a_cpy, int a_size);

t_stack	*convert_to_list(int *args, int argssize);
t_stack	*copy_list(t_stack *a);
void	*rtptr_free_list(void *rt, t_stack *a);
int		rtint_free_list(int rt, t_stack *a);

int		*bruteforce(t_stack **a, t_stack **b, int amount);
void	get_next_try(t_bf *params);
int		increment_and_fill(int *instructs, int incr,
			int b_size, int *instructs_size);
int		check_push(int *instructs, int i, int *b_size, int *instructs_size);
int		check_swap(int *instructs, int i, int b_size, int *instructs_size);
int		check_rotate(int *instructs, int i, int b_size, int *instructs_size);
int		check_rrotate(int *instructs, int i, int b_size, int *instructs_size);
int		check_smallest_index(int *instructs, int s_ind, int a_size, int b_size);
int		strict_checks(t_bf *params, int rt);

int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		sa(t_stack **a, t_stack **b);
int		sb(t_stack **a, t_stack **b);
int		ss(t_stack **a, t_stack **b);
int		ra(t_stack **a, t_stack **b);
int		rb(t_stack **a, t_stack **b);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **a, t_stack **b);
int		rrb(t_stack **a, t_stack **b);
int		rrr(t_stack **a, t_stack **b);

#endif
/*
void    check_list(t_stack *a);
*/
