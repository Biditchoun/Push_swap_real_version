/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_instructs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:12:46 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/18 17:56:12 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack **a, t_stack **b, int fd)
{
	(void)b;
	if (!a || !*a || !(*a)->next)
		return (0);
	(*a)->prev->next = *a;
	(*a)->prev->prev->next = NULL;
	*a = (*a)->prev;
	write(fd, "rra\n", 4);
	return (1);
}

int	rrb(t_stack **a, t_stack **b, int fd)
{
	(void)a;
	if (!b || !*b || !(*b)->next)
		return (0);
	(*b)->prev->next = *b;
	(*b)->prev->prev->next = NULL;
	*b = (*b)->prev;
	write(fd, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack **a, t_stack **b, int fd)
{
	rra(a, b, 3);
	rrb(a, b, 3);
	write(fd, "rrr\n", 4);
	return (1);
}
