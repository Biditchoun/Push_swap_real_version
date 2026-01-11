/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_get_next_try.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:14:34 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/11 22:23:16 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	increment_and_fill(int *instructs, int i, int b_size, int *instructs_size)
{
	if (instructs[i] == 10)
	{
		while (i > -1 && instructs[i] == 10)
			i--;
		if (i != -1)
			return (increment_and_fill(instructs, i, b_size, instructs_size));
		while (instructs[++i] > -1)
			instructs[i] = 1;
		instructs[i] = 1;
		instructs[++i] = -1;
		(*instructs_size)++;
		return (increment_and_fill(instructs, i - 1, 0, instructs_size));
	}
	if (instructs[i] == -1)
		return (0);
	instructs[i]++;
	if (instructs[i] == 1)
		b_size++;
	while (instructs[++i] > -1 && b_size-- >= 0)
		instructs[i] = 0;
	while (instructs[i] > -1)
		instructs[i++] = 1;
	return (1);
}

int	invalid_pushes(t_bf *params, int i, int b_size)
{
	int	b_instr;

	b_instr = 0;
	while (i-- && --b_size - b_instr > 0)
		if (params->instructs[i] == 1)
			b_instr++;
	return (increment_and_fill(params->instructs, i,
			b_instr, &params->instructs_size));
}

int	get_next_valid_instructs(t_bf *params)
{
	int	i;
	int	rt;
	int	b_size;
	int	*is;

	is = &params->instructs_size;
	i = -1;
	rt = 0;
	b_size = 0;
	while (params->instructs[++i] > -1 && !rt)
	{
		if (params->instructs[i] <= 1)
			rt = (check_push(params->instructs, i, &b_size, is));
		else if (params->instructs[i] <= 4)
			rt = (check_swap(params->instructs, i, b_size, is));
		else if (params->instructs[i] <= 7)
			rt = (check_rotate(params->instructs, i, b_size, is));
		else
			rt = (check_rrotate(params->instructs, i, b_size, is));
		if (b_size < 0 && !rt)
			return (increment_and_fill(params->instructs, i, b_size, is));
	}
	if (!rt && b_size)
		return (invalid_pushes(params, i, b_size));
	return (rt);
}

void	get_next_try(t_bf *params, t_stack **a)
{
	int	i;

	increment_and_fill(params->instructs, params->instructs_size - 1,
		0, &params->instructs_size);
	i = 1;
	while (i)
	{
		i = get_next_valid_instructs(params);
		if (params->amount_to_sort < params->stack_size)
			i = strict_checks(params, a, i);
	}
}
