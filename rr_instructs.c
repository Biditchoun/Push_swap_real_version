/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_instructs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:12:46 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/12 20:18:58 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **a, t_stack **b)
{
	(void)b;
	if (!a || !*a || !(*a)->next)
		return (0);
	(*a)->prev->next = *a;
	(*a)->prev->prev->next = NULL;
	*a = (*a)->prev;
	return (1);
}

int	rrb(t_stack **a, t_stack **b)
{
	(void)a;
	if (!b || !*b || !(*b)->next)
		return (0);
	(*b)->prev->next = *b;
	(*b)->prev->prev->next = NULL;
	*b = (*b)->prev;
	return (1);
}

int	rrr(t_stack **a, t_stack **b)
{
	rra(a, b);
	rrb(a, b);
	return (1);
}
