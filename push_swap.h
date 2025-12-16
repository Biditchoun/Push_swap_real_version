/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:19:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/16 15:56:26 by sawijnbe         ###   ########.fr       */
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

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct	s_bruteforce
{
	int		instructs[BRUTEFORCE];
	void	*f_instructs[12];
	char	f_write[12][5];
	int		amount_to_sort;
}	t_bf;

typedef struct	s_algo
{
	int	curr_moves;
	int	min_moves;
	int	algo_nb;
	int	algo_param;
}	t_algo;

int		check_argssize(int ac, char **av);
int		*convert_to_arr(char **av, int argssize);
int		check_if_sorted(int *a, int a_size);
void	bubble_sort(int *a, int a_size);
void	replace_value_with_index(int *a, int *a_cpy, int a_size);
t_stack	*convert_to_lists(int *args, int argssize);

int		bruteforce(t_stack **a, t_stack **b, int amount, int fd);

void	*free_list_rtptr(t_stack *start, void *rt);
t_stack	*get_last_node(t_stack *a);
t_stack	*copy_list(t_stack *a);

int		pa(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		pb(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		sa(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		sb(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		ss(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		ra(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		rb(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		rr(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		rra(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		rrb(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);
int		rrr(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b);

#endif
