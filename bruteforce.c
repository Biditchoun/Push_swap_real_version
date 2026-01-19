/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/19 23:02:25 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_params(t_bf *params, t_stack *a, t_stack *b)
{
	params->instructs[0] = 1;
	params->instructs[1] = -1;
	params->instructs_size = 1;
	params->smallest_nb = INT_MAX;
	params->a_size = 0;
	while (a)
	{
		if (a->nb < params->smallest_nb && params->a_size < params->a_amount)
			params->smallest_index = params->a_size + 1;
		if (params->a_size++ < params->a_amount && a->nb < params->smallest_nb)
			params->smallest_nb = a->nb;
		a = a->next;
	}
	params->b_size = 0;
	while (b)
	{
		if (b->nb < params->smallest_nb && params->b_size < params->b_amount)
			params->smallest_index = -params->b_size - 1;
		if (params->b_size++ < params->b_amount && b->nb < params->smallest_nb)
			params->smallest_nb = b->nb;
		b = b->next;
	}
	params->amount_to_sort = min(params->a_amount, params->a_size)
		+ min(params->b_amount, params->b_size);
}

int	check_if_brutesorted(t_stack *a, int amount)
{
	int	max;

	max = -1;
	while (amount-- && a)
	{
		if (max > a->nb)
			return (0);
		max = a->nb;
		a = a->next;
	}
	return (1);
}

int	apply_instructs(t_stack **a, t_stack **b,
		int *instructs, void **f_instructs)
{
	int	(*f)(t_stack **, t_stack **);
	int	i;

	i = -1;
	while (instructs[++i] > -1)
	{
		f = f_instructs[instructs[i]];
		f(a, b);
	}
	return (i);
}

void	undo_changes(t_stack **a, t_stack **b, t_bf *params)
{
	void	**f_instructs;
	int		(*f)(t_stack **, t_stack **);
	int		*instructs;
	int		i;

	f_instructs = params->f_instructs;
	instructs = params->instructs;
	i = params->instructs_size;
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
		else
			f = f_instructs[instructs[i] - 3];
		f(a, b);
	}
}

int	*bruteforce(t_stack **a, t_stack **b, int a_amount, int b_amount)
{
	t_bf		params;
	static void	*f_instructs[12] = {&pa, &pb, &sa, &sb, &ss,
		&ra, &rb, &rr, &rra, &rrb, &rrr, NULL};
	int			rt;

	params.a_amount = a_amount;
	params.b_amount = b_amount;
	params.f_instructs = f_instructs;
	initialise_params(&params, *a, *b);
	while (params.instructs_size <= BRUTEFORCE)
	{
		get_next_try(&params);
		while (check_smallest_index(params.instructs, params.smallest_index,
				params.a_size, params.b_size))
			get_next_try(&params);
/*#include <stdio.h>
int i = -1;
while (params.instructs[++i] > -1)
	printf("%i ", params.instructs[i]);
printf("\n");*/
		apply_instructs(a, b, params.instructs, params.f_instructs);
		rt = check_if_brutesorted(*a, params.amount_to_sort);
		undo_changes(a, b, &params);
		if (rt)
			return (arr_dup(params.instructs, params.instructs_size + 1));
	}
	return (NULL);
}
