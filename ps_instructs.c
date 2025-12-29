/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_instructs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 17:57:30 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/28 22:47:50 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pa(t_stack **a, t_stack **b, int fd)
{
	t_stack	*node_to_move;

	if (!b || !*b)
		return (0);
	node_to_move = *b;
	*b = (*b)->next;
	if (*b)
		(*b)->prev = node_to_move->prev;
	node_to_move->prev = node_to_move;
	if (*a)
		node_to_move->prev = (*a)->prev;
	if (*a)
		(*a)->prev = node_to_move;
	node_to_move->next = *a;
	*a = node_to_move;
	if (fd)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack **a, t_stack **b, int fd)
{
	t_stack	*node_to_move;

	if (!a || !*a)
		return (0);
	node_to_move = *a;
	*a = (*a)->next;
	if (*a)
		(*a)->prev = node_to_move->prev;
	node_to_move->prev = node_to_move;
	if (*b)
		node_to_move->prev = (*b)->prev;
	if (*b)
		(*b)->prev = node_to_move;
	node_to_move->next = *b;
	*b = node_to_move;
	if (fd)
		write(1, "pb\n", 3);
	return (1);
}

int	sa(t_stack **a, t_stack **b, int fd)
{
	int	buff;

	(void)b;
	if (!a || !*a || !(*a)->next)
		return (0);
	buff = (*a)->nb;
	(*a)->nb = (*a)->next->nb;
	(*a)->next->nb = buff;
	if (fd)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack **a, t_stack **b, int fd)
{
	int	buff;

	(void)a;
	if (!b || !*b || !(*b)->next)
		return (0);
	buff = (*b)->nb;
	(*b)->nb = (*b)->next->nb;
	(*b)->next->nb = buff;
	if (fd)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack **a, t_stack **b, int fd)
{
	sa(a, b, 0);
	sb(a, b, 0);
	if (fd)
		write(1, "ss\n", 3);
	return (1);
}
