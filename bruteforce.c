/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/29 01:15:02 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_params(t_bf *params, t_stack **a, int amount)
{
	t_stack	*curr;

	params->instructs[BRUTEFORCE] = -1;
	params->instructs[0] = -1;
	params->f_instructs[0] = &pa;
	params->f_instructs[1] = &pb;
	params->f_instructs[2] = &sa;
	params->f_instructs[3] = &sb;
	params->f_instructs[4] = &ss;
	params->f_instructs[5] = &ra;
	params->f_instructs[6] = &rb;
	params->f_instructs[7] = &rr;
	params->f_instructs[8] = &rra;
	params->f_instructs[9] = &rrb;
	params->f_instructs[10] = &rrr;
	params->f_instructs[11] = NULL;
	params->stack_size = 0;
	curr = *a;
	while (curr)
	{
		curr = curr->next;
		params->stack_size++;
	}
	params->amount_to_sort = min(amount, params->stack_size);
}

int	check_if_brutesorted(t_stack *a_cpy, int amount)
{
	int		max;

	max = -1;
	while (amount-- && a_cpy)
	{
		if (max > a_cpy->nb)
			return (0);
		max = a_cpy->nb;
		a_cpy = a_cpy->next;
	}
	return (1);
}

int	apply_instructs(t_stack **a, t_stack **b, t_bf params, int fd)
{
	int		(*f)(t_stack **, t_stack **, int);
	int		i;

	i = -1;
	while (params.instructs[++i] > -1)
	{
		f = params.f_instructs[params.instructs[i]];
		f(a, b, fd);
	}
	return (i);
}

void	undo_changes(t_stack **a_cpy, t_stack **b_cpy,
		int *instructs, void **f_instructs)
{
	int	(*f)(t_stack **, t_stack **, int);
	int	i;

	i = 0;
	while (instructs[i] > -1)
		i++;
	while (--i > -1)
	{
		if (instructs[i] == 0)
			f = f_instructs[1];
		else if (instructs[i] == 1)
			f = f_instructs[0];
		else if (instructs[i] >= 2 && instructs[i] <= 4)
			f = f_instructs[instructs[i]];
		else if (instructs[i] >= 5 && instructs[i] <= 7)
			f = f_instructs[instructs[i] + 3];
		else if (instructs[i] >= 8 && instructs[i] <= 10)
			f = f_instructs[instructs[i] - 3];
		f(a_cpy, b_cpy, 0);
	}
}

int	bruteforce(t_stack **a, t_stack **b, int amount, int fd)
{
	t_bf	params;
	t_stack	*a_cpy;
	t_stack	*b_cpy;
	int		rt;

	initialise_params(&params, a, amount);
	rt = 0;
	a_cpy = copy_list(*a);
	b_cpy = copy_list(*b);
	if ((*a && !a_cpy) || (*b && !b_cpy))
		return (free_lists_rtint(a_cpy, b_cpy, 0));
	while (params.instructs[BRUTEFORCE] < 0)
	{
/*#include <stdio.h>
int i = -1;
while (params.instructs[++i] > -1)
	printf("%i ", params.instructs[i]);
printf("\n");*/
		get_next_try(&params, a);
		apply_instructs(&a_cpy, &b_cpy, params, 0);
		if (check_if_brutesorted(a_cpy, params.amount_to_sort))
			rt = apply_instructs(a, b, params, fd);
		if (rt)
			return (free_lists_rtint(a_cpy, b_cpy, rt));
		undo_changes(&a_cpy, &b_cpy, params.instructs, params.f_instructs);
	}
	return (free_lists_rtint(a_cpy, b_cpy, 0));
}
