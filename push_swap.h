/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:19:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/29 00:39:22 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

# ifndef BRUTEFORCE
#  define BRUTEFORCE 12
# endif

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
	void	*f_instructs[12];
	int		amount_to_sort;
	int		stack_size;
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
void	*free_lists_rtptr(t_stack *l1, t_stack *l2, void *rt);
int		free_lists_rtint(t_stack *l1, t_stack *l2, int rt);

int		bruteforce(t_stack **a, t_stack **b, int amount, int fd);
void	get_next_try(t_bf *params, t_stack **a);
int		increment_and_fill(int *instructs, int incr);
int		check_pushes(int *instructs);
int		check_b_instructs(int *instructs);
int		check_opposite_instructs(int *instr);

int		pa(t_stack **a, t_stack **b, int fd);
int		pb(t_stack **a, t_stack **b, int fd);
int		sa(t_stack **a, t_stack **b, int fd);
int		sb(t_stack **a, t_stack **b, int fd);
int		ss(t_stack **a, t_stack **b, int fd);
int		ra(t_stack **a, t_stack **b, int fd);
int		rb(t_stack **a, t_stack **b, int fd);
int		rr(t_stack **a, t_stack **b, int fd);
int		rra(t_stack **a, t_stack **b, int fd);
int		rrb(t_stack **a, t_stack **b, int fd);
int		rrr(t_stack **a, t_stack **b, int fd);

#endif
/*
void    check_list(t_stack *a);
*/
