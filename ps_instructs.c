/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:57:30 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/11 18:36:25 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack **a, t_stack **b)
{
	t_stack	*node_to_move;

	if (!*b)
		return (0);
	node_to_move = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = NULL;
	if (*a)
		(*a)->prev = node_to_move;
	node_to_move->next = *a;
	*a = node_to_move;
	return (1);
}

int	pb(t_stack **a, t_stack **b)
{
	t_stack	*node_to_move;

	if (!*a)
		return (0);
	node_to_move = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = NULL;
	if (*b)
		(*b)->prev = node_to_move;
	node_to_move->next = *b;
	*b = node_to_move;
	return (1);
}

int	sa(t_stack **a)
{
	t_stack	*future_first_node;

	if (!*a || !(*a)->next)
		return (0);
	future_first_node = (*a)->next;
	if (future_first_node->next)
		future_first_node->next->prev = *a;
	(*a)->prev = future_first_node;
	(*a)->next = future_first_node->next;
	future_first_node->prev = NULL;
	future_first_node->next = *a;
	*a = future_first_node;
	return (1);
}

int	sb(t_stack **b)
{
	t_stack	*future_first_node;

	if (!*b || !(*b)->next)
		return (0);
	future_first_node = (*b)->next;
	if (future_first_node->next)
		future_first_node->next->prev = *b;
	(*b)->prev = future_first_node;
	(*b)->next = future_first_node->next;
	future_first_node->prev = NULL;
	future_first_node->next = *b;
	*b = future_first_node;
	return (1);
}

int	ss(t_stack **a, t_stack **b)
{
	sa(a);
	sb(b);
	return (1);
}
