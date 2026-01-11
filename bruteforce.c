/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/11 21:49:02 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	initialise_params(t_bf *params, t_stack *a, int amount)
{
	params->instructs[0] = 1;
	params->instructs[1] = -1;
	params->instructs_size = 1;
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
	while (a)
	{
		a = a->next;
		params->stack_size++;
	}
	params->amount_to_sort = min(amount, params->stack_size);
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

int	apply_instructs(t_stack **a, t_stack **b, t_bf params, int fd)
{
	int	(*f)(t_stack **, t_stack **, int);
	int	i;

	i = -1;
	while (params.instructs[++i] > -1)
	{
		f = params.f_instructs[params.instructs[i]];
		f(a, b, fd);
	}
	return (i);
}

void	undo_changes(t_stack **a, t_stack **b,
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
		f(a, b, 0);
	}
}

int	bruteforce(t_stack **a, t_stack **b, int amount, int fd)
{
	t_bf	params;
	int		rt;

	initialise_params(&params, *a, amount);
	while (params.instructs_size <= BRUTEFORCE)
	{
		get_next_try(&params, a);
		apply_instructs(a, b, params, 0);
/*#include <stdio.h>
int i = -1;
while (params.instructs[++i] > -1)
	printf("%i ", params.instructs[i]);
printf("\n");*/
		rt = check_if_brutesorted(*a, params.amount_to_sort);
		undo_changes(a, b, params.instructs, params.f_instructs);
		if (rt)
			rt = apply_instructs(a, b, params, fd);
		if (rt)
			return (rt);
	}
	return (0);
}
