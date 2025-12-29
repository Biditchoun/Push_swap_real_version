/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_basic_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:50:16 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/29 00:39:04 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pushes(int *instructs)
{
	int	b_size;
	int	i;

	b_size = 0;
	i = -1;
	while (instructs[++i] > -1)
	{
		if (instructs[i] == 0)
			b_size--;
		else if (instructs[i] == 1)
			b_size++;
		if (b_size < 0
			|| (instructs[i] == 0 && instructs[i + 1] == 1)
			|| (instructs[i] == 1 && instructs[i + 1] == 0))
			break ;
	}
	if (b_size == 0 && instructs[i] == -1)
		return (0);
	if (instructs[i] != -1 && b_size >= 0)
		i++;
	if (instructs[i] == -1)
		i--;
	return (increment_and_fill(instructs, i));
}

int	check_b_instructs(int *instructs)
{
	int	i;
	int	b_size;

	b_size = 0;
	i = -1;
	while (instructs[++i] > -1)
	{
		if (instructs[i] == 0)
			b_size--;
		else if (instructs[i] == 1)
			b_size++;
		else if ((b_size < 2 && instructs[i] != 2
				&& instructs[i] != 5 && instructs[i] != 8)
			|| (b_size == 2 && (instructs[i] == 6 || instructs[i] == 7
					|| instructs[i] == 9 || instructs[i] == 10)))
			break ;
	}
	if (instructs[i] > 8)
		instructs[i] = 10;
	else if (instructs[i] > 5)
		instructs[i] = 7;
	else if (instructs[i] > 2)
		instructs[i] = 4;
	return (increment_and_fill(instructs, i));
}

int	check_opposite_instructs(int *instr)
{
	int	i;

	i = -1;
	while (instr[++i] > -1)
		if ((instr[i] == 2 && (instr[i + 1] == 2 || instr[i + 1] == 4))
			|| (instr[i] == 3 && (instr[i + 1] == 3 || instr[i + 1] == 4))
			|| (instr[i] == 4 && instr[i + 1] >= 2 && instr[i + 1] <= 4)
			|| (instr[i] == 5 && (instr[i + 1] == 8 || instr[i + 1] == 10))
			|| (instr[i] == 6 && (instr[i + 1] == 9 || instr[i + 1] == 10))
			|| (instr[i] == 7 && instr[i + 1] >= 8 && instr[i + 1] <= 10)
			|| (instr[i] == 8 && (instr[i + 1] == 5 || instr[i + 1] == 7))
			|| (instr[i] == 9 && (instr[i + 1] == 6 || instr[i + 1] == 7))
			|| (instr[i] == 10 && instr[i + 1] >= 5 && instr[i + 1] <= 7))
			break ;
	if (instr[i] == 3 || instr[i] == 4)
		instr[i + 1] = 4;
	else if (instr[i] == 6 || instr[i] == 7)
		instr[i + 1] = 10;
	else if (instr[i] == 9 || instr[i] == 10)
		instr[i + 1] = 7;
	if (instr[i] != -1)
		i++;
	return (increment_and_fill(instr, i));
}
