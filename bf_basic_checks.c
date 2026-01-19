/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_basic_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:50:16 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/19 22:57:56 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_push(t_bf *params, int i, int *a_size, int *b_size)
{
	int	*instructs;

	instructs = params->instructs;
	if (!instructs[i])
		(*b_size)--;
	else
		(*b_size)++;
	if (!instructs[i])
		(*a_size)++;
	else
		(*a_size)--;
	if ((instructs[i] == 0 && instructs[i + 1] == 1)
		|| (instructs[i] == 1 && instructs[i + 1] == 0))
		return (increment_and_fill(params, i + 1, *b_size));
	return (0);
}

int	check_swap(t_bf *params, int i, int a_size, int b_size)
{
	int	b;
	int	*instructs;

	instructs = params->instructs;
	if (a_size < 2 && instructs[i] != 3)
		return (increment_and_fill(params, i, b_size));
	if (b_size < 2 && instructs[i] != 2)
	{
		instructs[i] = 4;
		return (increment_and_fill(params, i, b_size));
	}
	b = 0;
	if (instructs[i++] == 2)
		b = 1;
	while (instructs[i] != -1
		&& (instructs[i] == 5 + b || instructs[i] == 8 + b))
		i++;
	if (instructs[i] >= 2 && instructs[i] <= 4)
	{
		instructs[i] = 4;
		return (increment_and_fill(params, i, b_size));
	}
	return (0);
}

int	check_rotate(t_bf *params, int i, int a_size, int b_size)
{
	int	curr;
	int	*instructs;

	instructs = params->instructs;
	if ((a_size < 2 && instructs[i] != 6) || (a_size == 2 && instructs[i] == 5))
		return (increment_and_fill(params, i, b_size));
	if ((b_size < 2 && instructs[i] != 5) || (b_size == 2 && instructs[i] == 6))
	{
		if (b_size < 2)
			instructs[i] = 7;
		return (increment_and_fill(params, i, b_size));
	}
	curr = instructs[i++];
	if ((curr == 7 && instructs[i] >= 8 && instructs[i] <= 10)
		|| (curr == 6 && instructs[i] >= 9))
	{
		instructs[i] = 10;
		return (increment_and_fill(params, i, b_size));
	}
	if ((curr == 6 && instructs[i] == 5) || (curr == 5
			&& (instructs[i] == 6 || instructs[i] == 8 || instructs[i] == 10)))
		return (increment_and_fill(params, i, b_size));
	return (0);
}

int	check_rrotate(t_bf *params, int i, int a_size, int b_size)
{
	int	curr;
	int	*instr;

	instr = params->instructs;
	if ((a_size < 2 && instr[i] != 9) || (a_size == 2 && instr[i] == 8))
		return (increment_and_fill(params, i, b_size));
	if ((b_size < 2 && instr[i] != 8) || (b_size == 2 && instr[i] == 9))
	{
		instr[i] = 10;
		return (increment_and_fill(params, i, b_size));
	}
	curr = instr[i++];
	if (curr == 10 && instr[i] >= 5 && instr[i] <= 7)
	{
		instr[i] = 7;
		return (increment_and_fill(params, i, b_size));
	}
	if (curr == 9 && instr[i] >= 6 && instr[i] <= 8)
	{
		instr[i] = 8;
		return (increment_and_fill(params, i, b_size));
	}
	if (curr == 8 && (instr[i] == 9 || instr[i] == 5 || instr[i] == 7))
		return (increment_and_fill(params, i, b_size));
	return (0);
}
