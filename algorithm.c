/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:08:44 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/04 17:45:39 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *index, int nb)
{
	int	i;

	i = -1;
	while (++i < index->size)
		if (index->stack[i] == nb)
			return (i);
	return (-1);
}

int	get_closest_to_push(t_stack *a, t_stack *index, int chunk_size)
{
	int	i;
	int	j;

	i = -1;
	j = a->size;
	while (++i < a->size)
	{
		if (get_index(index, a->stack[i]) < chunk_size)
		{
			while (i--)
				ra(a, 1);
			return (0);
		}
		j--;
		if (get_index(index, a->stack[j]) < chunk_size)
		{
			while (j++ < a->size)
				rra(a, 1);
			return (0);
		}
	}
	return (-1);
}

int	get_to_biggest(t_stack *b, t_stack *index)
{
	int	i;

	if (b->size == 1 || get_index(index, b->stack[0]) == b->size - 1)
		return (0);
	if (get_index(index, b->stack[1]) == b->size - 1)
		return (sb(b, 1) - 1);
	i = -1;
	while (++i < b->size)
		if (get_index(index, b->stack[i]) == b->size - 1)
			break ;
	if (b->size / i > 1)
		rb(b, 1);
	else
		rrb(b, 1);
	return (get_to_biggest(b, index));
}

int	push_all_to_b(t_stack *a, t_stack *b, t_stack *index, int chunk_size)
{
	int	pb_count;

	pb_count = 0;
	while (a->size && index->size - chunk_size < a->size)
	{
		get_closest_to_push(a, index, chunk_size);
		pb_count += pb(a, b, 1);
		if (pb_count % 2)
			rb(b, 1);
	}
	if (index->size > 100)
		chunk_size += index->size / 10;
	else
		chunk_size += index->size / 5;
	if (a->size)
		push_all_to_b(a, b, index, chunk_size);
	return (0);
}

int	sort_this_shit(t_stack *a, t_stack *b, t_stack *index)
{
	if (a->size > 100)
		push_all_to_b(a, b, index, a->size / 10);
	else
		push_all_to_b(a, b, index, a->size / 5);
	while (b->size)
	{
		get_to_biggest(b, index);
		pa(a, b, 1);
	}
	return (0);
}
