/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_on_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 12:32:52 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/16 14:04:20 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_list_rtptr(t_stack *start, void *rt)
{
	while (start->next)
	{
		start = start->next;
		free(start->prev);
	}
	free(start);
	return (rt);
}

t_stack	*get_last_node(t_stack *a)
{
	if (!a)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

t_stack	*copy_list(t_stack *a)
{
	t_stack	*rt;
	t_stack	*curr;
	t_stack	*prev;

	rt = malloc(sizeof(t_stack));
	if (!rt)
		return (NULL);
	curr = rt;
	prev = NULL;
	while (a)
	{
		curr->nb = a->nb;
		curr->prev = prev;
		a = a->next;
		prev = curr;
		if (a)
			curr->next = malloc(sizeof(t_stack));
		else
			curr->next = NULL;
		if (!(curr->next) && a)
			return (free_list_rtptr(rt, NULL));
		curr = curr->next;
	}
	return (rt);
}
