/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:19:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/02/24 22:19:53 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# if BRUTEFORCE < 0
#  undef BRUTEFORCE
#  define BRUTEFORCE 0
# endif

int		check_argssize(int ac, char **av);
int		*convert_to_arr(char **av, int argssize);
int		check_if_sorted(int *a, int a_size);
void	replace_value_with_index(int *a, int *a_cpy, int a_size);

typedef struct s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*convert_to_list(int *args, int argssize);
t_stack	*copy_list(t_stack *a);
void	*rtptr_free_list(void *rt, t_stack *a);
int		rtint_free_list(int rt, t_stack *a);

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

typedef struct s_bruteforce
{
	int		*instructs;
	int		instructs_size;
	int		instructs_msize;
	void	**f_instructs;
	int		a_size;
	int		b_size;
	int		a_amount;
	int		b_amount;
	int		amount_to_sort;
	int		smallest_nb;
	int		smallest_index;
}	t_bf;

int		*brute_push_and_brute(t_stack **a, t_stack **b, int a_size);
int		*bruteforce(t_stack **a, t_stack **b, int a_amount, int b_amount);
void	get_next_try(t_bf *params);
int		increment_and_fill(t_bf *params, int i, int b_size);
int		check_push(t_bf *params, int i, int *a_size, int *b_size);
int		check_swap(t_bf *params, int i, int a_size, int b_size);
int		check_rotate(t_bf *params, int i, int a_size, int b_size);
int		check_rrotate(t_bf *params, int i, int a_size, int b_size);
int		strict_checks(t_bf *params, int rt, int a_top, int b_top);
int		check_smallest_index(int *instructs, int s_ind, int a_size, int b_size);

typedef struct s_algo
{
	void	(*f)(t_stack **, struct s_algo *, int);
	int		min_moves;
	int		curr_moves;
	int		*instructs;
	int		*curr_instructs;
}	t_algo;

int		apply_instructs(t_stack **a, t_stack **b,
			int *instructs, void **f_instructs);
int		*clean_instructs(int *instructs);

typedef struct s_bc
{
	void	**f_instructs;
	t_stack	*a[1];
	t_stack	*b[1];
	int		instructs[111111];
	int		nb_amount;
	int		a_size;
	int		chunk_size;
}	t_bc;

void	brute_chunks(t_stack **a, t_algo *info, int a_size);
int		push_all_to_b(t_bc *par);

#endif

void	check_list(t_stack *a);
