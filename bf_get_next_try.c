/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_get_next_try.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:14:34 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/02/24 22:19:35 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	increment_and_fill(t_bf *params, int i, int b_size)
{
	int	*instructs;

	instructs = params->instructs;
	if (instructs[i] == 10)
	{
		while (i > -1 && instructs[i] == 10)
			i--;
		if (i != -1)
			return (increment_and_fill(params, i, b_size));
		while (instructs[++i] > -1)
			instructs[i] = 1;
		instructs[i] = 1;
		instructs[++i] = -1;
		params->instructs_size++;
		return (increment_and_fill(params, i - 1, 0));
	}
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
	int	pb_instructs;

	pb_instructs = 0;
	while (i-- && --b_size - pb_instructs > 0)
		if (params->instructs[i] == 1)
			pb_instructs++;
	if (i < 0)
		i = 0;
	return (increment_and_fill(params, i, pb_instructs));
}

int	get_next_valid_instructs(t_bf *params, int *instructs)
{
	int	i;
	int	rt;
	int	a_size;
	int	b_size;

	i = -1;
	rt = 0;
	a_size = min(params->a_size, params->a_amount);
	b_size = min(params->b_size, params->b_amount);
	while (instructs[++i] > -1 && !rt)
	{
		if (instructs[i] <= 1)
			rt = (check_push(params, i, &a_size, &b_size));
		else if (instructs[i] <= 4)
			rt = (check_swap(params, i, a_size, b_size));
		else if (instructs[i] <= 7)
			rt = (check_rotate(params, i, a_size, b_size));
		else
			rt = (check_rrotate(params, i, a_size, b_size));
		if (!rt && (a_size < 0 || b_size < 0))
			return (increment_and_fill(params, i, b_size));
	}
	if (!rt && b_size)
		return (invalid_pushes(params, i, b_size));
	return (rt);
}

void	get_next_try(t_bf *params)
{
	int	valid;

	if (params->instructs[params->instructs_size - 1] != 10)
		params->instructs[params->instructs_size - 1]++;
	else
		increment_and_fill(params, params->instructs_size - 1, params->b_size);
	valid = 1;
	while (valid && params->instructs_size < params->instructs_msize)
	{
		valid = get_next_valid_instructs(params, params->instructs);
		if (params->a_amount < params->a_size
			|| params->b_amount < params->b_size)
			valid = strict_checks(params, valid, params->a_amount, params->b_amount);
	}
}
