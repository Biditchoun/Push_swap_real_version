/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_get_next_try.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:14:34 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/29 00:24:41 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	end_case(int *instructs, int i)
{
	while (i > -1 && instructs[i] == 10)
		i--;
	if (i != -1)
		return (increment_and_fill(instructs, i));
	while (instructs[++i] > -1)
		instructs[i] = 0;
	instructs[i] = 0;
	instructs[++i] = -1;
	return (increment_and_fill(instructs, 0));
}

int	increment_and_fill(int *instructs, int incr)
{
	int	i;
	int	b_size;

	if (instructs[incr] == 10)
		return (end_case(instructs, incr));
	if (instructs[incr] == -1)
		return (0);
	b_size = 0;
	i = -1;
	while (++i < incr)
	{
		if (instructs[i] == 0)
			b_size--;
		if (instructs[i] == 1)
			b_size++;
	}
	instructs[i]++;
	if (instructs[i] == 1)
		b_size++;
	while (instructs[++i] > -1 && b_size--)
		instructs[i] = 0;
	incr = 0;
	while (instructs[i] > -1)
		instructs[i++] = ++incr % 2;
	return (1);
}

int	get_next_valid_instructs(t_bf *params, t_stack **a)
{
	(void)a;
	if (check_pushes(params->instructs))
		return (1);
	if (check_b_instructs(params->instructs))
		return (2);
	if (check_opposite_instructs(params->instructs))
		return (3);
	return (0);
}

void	get_next_try(t_bf *params, t_stack **a)
{
	int	i;

	i = 0;
	while (params->instructs[i] > -1)
		i++;
	if (i == 0)
	{
		params->instructs[i]++;
		params->instructs[++i] = -1;
	}
	increment_and_fill(params->instructs, i - 1);
	i = 1;
	while (i)
		i = get_next_valid_instructs(params, a);
}
