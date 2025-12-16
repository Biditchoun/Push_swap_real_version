/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_instructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:12:46 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/16 14:19:23 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b)
{
	t_stack	*node_to_move;

	(void)b;
	(void)last_b;
	if (!*a || !(*a)->next)
		return (0);
	node_to_move = *a;
	*a = (*a)->next;
	(*a)->prev = NULL;
	node_to_move->prev = *last_a;
	node_to_move->next = NULL;
	(*last_a)->next = node_to_move;
	*last_a = node_to_move;
	return (1);
}

int	rb(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b)
{
	t_stack	*node_to_move;

	(void)a;
	(void)last_a;
	if (!*b || !(*b)->next)
		return (0);
	node_to_move = *b;
	*b = (*b)->next;
	(*b)->prev = NULL;
	node_to_move->prev = *last_b;
	node_to_move->next = NULL;
	(*last_b)->next = node_to_move;
	*last_b = node_to_move;
	return (1);
}

int	rr(t_stack **a, t_stack **last_a, t_stack **b, t_stack **last_b)
{
	ra(a, last_a, b, Last_b);
	rb(a, last_a, b, last_b);
	return (1);
}
