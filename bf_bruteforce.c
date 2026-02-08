/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_bruteforce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/02/08 17:55:36 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_params(t_bf *params, t_stack *a, t_stack *b)
{
	params->smallest_nb = INT_MAX;
	params->a_size = 0;
	params->b_size = 0;
	while (a || b)
	{
		if (a && a->nb < params->smallest_nb
			&& params->a_size < params->a_amount)
			params->smallest_index = params->a_size + 1;
		if (a && params->a_size++ < params->a_amount
			&& a->nb < params->smallest_nb)
			params->smallest_nb = a->nb;
		if (a)
			a = a->next;
		if (b && b->nb < params->smallest_nb
			&& params->b_size < params->b_amount)
			params->smallest_index = -params->b_size - 1;
		if (b && params->b_size++ < params->b_amount
			&& b->nb < params->smallest_nb)
			params->smallest_nb = b->nb;
		if (b)
			b = b->next;
	}
	params->amount_to_sort = min(params->a_amount, params->a_size)
		+ min(params->b_amount, params->b_size);
}

int	initialise_instructs(t_bf *params)
{
	params->instructs_msize = max(0, BRUTEFORCE - 2);
	if (params->a_amount > params->a_size && params->b_amount > params->b_size)
		params->instructs_msize = BRUTEFORCE;
	if (params->a_amount == INT_MAX - 1 || params->b_amount == INT_MAX - 1
		|| (params->a_amount < params->a_size
			&& params->b_amount < params->b_size))
		params->instructs_msize = 10;
	params->instructs = malloc(sizeof(int) * (params->instructs_msize + 2));
	if (!params->instructs)
		return (-1);
	params->instructs[0] = 1;
	params->instructs[1] = -1;
	params->instructs_size = 1;
	return (0);
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
	int			check_rt;

	params.a_amount = a_amount;
	params.b_amount = b_amount;
	params.f_instructs = f_instructs;
	initialise_params(&params, *a, *b);
	if (initialise_instructs(&params))
		return (NULL);
	while (params.instructs_size <= params.instructs_msize)
	{
		get_next_try(&params);
		while (check_smallest_index(params.instructs, params.smallest_index,
				params.a_size, params.b_size))
			get_next_try(&params);
		apply_instructs(a, b, params.instructs, params.f_instructs);
		check_rt = check_if_brutesorted(*a, params.amount_to_sort);
		undo_changes(a, b, &params);
		if (check_rt)
			return (params.instructs);
	}
	free(params.instructs);
	return (NULL);
}
