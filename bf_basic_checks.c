/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_basic_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:50:16 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/08 22:36:19 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_push(int *instructs, int i, int *b_size)
{
	if (instructs[i])
		(*b_size)++;
	else
		(*b_size)--;
	if ((instructs[i] == 0 && instructs[i + 1] == 1)
		|| (instructs[i] == 1 && instructs[i + 1] == 0))
		return (increment_and_fill(instructs, i + 1, *b_size));
	return (0);
}

int	check_swap(int *instructs, int i, int b_size)
{
	int	b;

	if (instructs[i] > 2 && b_size < 2)
		return (increment_and_fill(instructs, i, b_size));
	b = 0;
	if (instructs[i] == 2)
		b = 1;
	i++;
	while (instructs[i] != -1
		&& (instructs[i] == 5 + b || instructs[i] == 8 + b))
		i++;
	if (instructs[i] >= 2 && instructs[i] <= 4)
		return (increment_and_fill(instructs, i, b_size));
	return (0);
}

int	check_rotate(int *instructs, int i, int b_size)
{
	int	b;
	int	curr;

	if (b_size < 3 && (instructs[i] == 6 || instructs[i] == 7))
		return (increment_and_fill(instructs, i, b_size));
	curr = instructs[i++];
	b = 0;
	if (curr == 5)
		b = 1;
	while (instructs[i] != -1
		&& (instructs[i] == 2 + b || instructs[i] == 8 + b))
		i++;
	if ((curr == 7 && instructs[i] >= 8 && instructs[i] <= 10)
		|| (curr == 6 && (instructs[i] == 5 || instructs[i] >= 9))
		|| (curr == 5
			&& (instructs[i] == 6 || instructs[i] == 8 || instructs[i] == 10)))
		return (increment_and_fill(instructs, i, b_size));
	return (0);
}

int	check_rrotate(int *instructs, int i, int b_size)
{
	int	b;
	int	curr;

	if (b_size < 3 && instructs[i] >= 9)
		return (increment_and_fill(instructs, i, b_size));
	curr = instructs[i++];
	b = 0;
	if (curr == 8)
		b = 1;
	while (instructs[i] != -1
		&& (instructs[i] == 2 + b || instructs[i] == 5 + b))
		i++;
	if ((curr == 10 && instructs[i] >= 5 && instructs[i] <= 7)
		|| (curr == 9 && instructs[i] >= 6 && instructs[i] <= 8)
		|| (curr == 8
			&& (instructs[i] == 9 || instructs[i] == 5 || instructs[i] == 7)))
		return (increment_and_fill(instructs, i, b_size));
	return (0);
}
