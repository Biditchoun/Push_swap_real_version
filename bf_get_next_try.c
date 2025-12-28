/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_get_next_try.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:14:34 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/28 22:38:39 by sawijnbe         ###   ########.fr       */
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
	b_size = 0;
	i = -1;
	while (++i < incr)
	{
		if (instructs[i] == 0)
			b_size--;;
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

int	get_next_valid_instructs(int *instructs, int amount, t_stack **a)
{
	(void)a;
	(void)amount;
	if (check_nb_pushes(instructs))
		return (1);
	if (check_pushes_proximity(instructs))
		return (2);
	else if (check_b_actions(instructs))
		return (3);
	return (0);
}

void	get_next_try(int *instructs, int amount, t_stack **a)
{
	int	i;

	i = 0;
	while (instructs[i] > -1)
		i++;
	if (i == 0)
	{
		instructs[i]++;
		instructs[++i] = -1;
	}
	increment_and_fill(instructs, --i);
	i = 1;
	while (i)
		i = get_next_valid_instructs(instructs, amount, a);
}
