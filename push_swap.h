/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:19:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/11 18:37:25 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_stack
{
	int				nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int		check_argssize(int ac, char **av);
int		*convert_to_arr(char **av, int argssize);
int		check_if_sorted(int *a, int a_size);
void	bubble_sort(int *a, int a_size);
void	replace_value_with_index(int *a, int *a_cpy, int a_size);
t_stack	*convert_to_lists(int *args, int argssize);
void	*free_list_rtptr(t_stack *start, void *rt);

int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **a, t_stack **b);
int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);

#endif
