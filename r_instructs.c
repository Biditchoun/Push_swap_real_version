/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_instructs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 19:12:46 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/18 17:55:09 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack **a, t_stack **b, int fd)
{
	(void)b;
	if (!a || !*a || !(*a)->next)
		return (0);
	*a = (*a)->next;
	(*a)->prev->next = NULL;
	(*a)->prev->prev->next = (*a)->prev;
	write(fd, "ra\n", 3);
	return (1);
}

int	rb(t_stack **a, t_stack **b, int fd)
{
	(void)a;
	if (!b || !*b || !(*b)->next)
		return (0);
	*b = (*b)->next;
	(*b)->prev->next = NULL;
	(*b)->prev->prev->next = (*b)->prev;
	write(fd, "rb\n", 3);
	return (1);
}

int	rr(t_stack **a, t_stack **b, int fd)
{
	ra(a, b, 3);
	rb(a, b, 3);
	write(fd, "rr\n", 3);
	return (1);
}
