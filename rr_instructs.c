/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_instructs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:12:46 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/12 20:05:22 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **a, t_stack **last_a)
{
	t_stack	*node_to_move;

	if (!*a || !(*a)->next)
		return (0);
	node_to_move = *last_a;
	*last_a = (*last_a)->prev;
	(*last_a)->next = NULL;
	node_to_move->prev = NULL;
	node_to_move->next = *a;
	(*a)->prev = node_to_move;
	*a = node_to_move;
	return (1);
}

int	rrb(t_stack **b, t_stack **last_b)
{
	t_stack	*node_to_move;

	if (!*b || !(*b)->next)
		return (0);
	node_to_move = *last_b;
	*last_b = (*last_b)->prev;
	(*last_b)->next = NULL;
	node_to_move->prev = NULL;
	node_to_move->next = *b;
	(*b)->prev = node_to_move;
	*b = node_to_move;
	return (1);
}

int	rrr(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b)
{
	rra(a, last_a);
	rrb(b, last_b);
	return (1);
}
