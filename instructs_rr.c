/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_rr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:12:46 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/28 09:09:14 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **a, t_stack **b)
{
	(void)b;
	if (!a || !*a || !(*a)->next)
		return (-1);
	(*a)->prev->next = *a;
	(*a)->prev->prev->next = NULL;
	*a = (*a)->prev;
	return (8);
}

int	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	if (!b || !*b || !(*b)->next)
		return (-1);
	(*b)->prev->next = *b;
	(*b)->prev->prev->next = NULL;
	*b = (*b)->prev;
	return (9);
}

int	rrr(t_stack **a, t_stack **b)
{
	rra(a, b);
	rrb(a, b);
	return (10);
}
