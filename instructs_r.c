/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructs_r.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:12:46 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/22 19:59:51 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **a, t_stack **b)
{
	(void)b;
	if (!a || !*a || !(*a)->next)
		return (0);
	*a = (*a)->next;
	(*a)->prev->next = NULL;
	(*a)->prev->prev->next = (*a)->prev;
	return (5);
}

int	rb(t_stack **a, t_stack **b)
{
	(void)a;
	if (!b || !*b || !(*b)->next)
		return (0);
	*b = (*b)->next;
	(*b)->prev->next = NULL;
	(*b)->prev->prev->next = (*b)->prev;
	return (6);
}

int	rr(t_stack **a, t_stack **b)
{
	ra(a, b);
	rb(a, b);
	return (7);
}
