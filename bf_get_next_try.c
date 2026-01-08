/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_get_next_try.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:14:34 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/08 23:55:32 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end_case(int *instructs, int i, int b_size)
{
	while (i > -1 && instructs[i] == 10)
		i--;
	if (i != -1)
		return (increment_and_fill(instructs, i, b_size));
	while (instructs[++i] > -1)
		instructs[i] = 1;
	instructs[i] = 1;
	instructs[++i] = -1;
	return (increment_and_fill(instructs, i - 1, 0));
}

int	increment_and_fill(int *instructs, int i, int b_size)
{
	if (instructs[i] == 10)
		return (end_case(instructs, i, b_size));
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

int	strict_checks(t_bf *params, t_stack **a, int i)
{
	(void)params;
	(void)a;
	return (i);
}

int	get_next_valid_instructs(t_bf *params, int rt, int b_size, int b_instr)
{
	int	i;

	i = -1;
	while (params->instructs[++i] > -1 && !rt)
	{
		if (params->instructs[i] <= 1)
			rt = check_push(params->instructs, i, &b_size);
		else if (params->instructs[i] <= 4)
			rt = check_swap(params->instructs, i, b_size);
		else if (params->instructs[i] <= 7)
			rt = check_rotate(params->instructs, i, b_size);
		else
			rt = check_rrotate(params->instructs, i, b_size);
		if (b_size < 0 && !rt)
			return (increment_and_fill(params->instructs, i, b_size));
	}
	if (!rt && b_size)
	{
		while (i-- && --b_size - b_instr > 0)
			if (params->instructs[i] == 1)
				b_instr++;
		return (increment_and_fill(params->instructs, i, b_instr));
	}
	return (rt);
}

void	get_next_try(t_bf *params, t_stack **a)
{
	int	i;

	i = 0;
	while (params->instructs[i] > -1)
		i++;
	increment_and_fill(params->instructs, i - 1, 0);
	i = 1;
	while (i)
	{
		i = get_next_valid_instructs(params, 0, 0, 0);
		i = strict_checks(params, a, i);
	}
}
