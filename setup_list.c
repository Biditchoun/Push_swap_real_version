/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:17:48 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/23 23:11:46 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*convert_to_list(int *args, int argssize)
{
	t_stack	*rt;
	t_stack	*current;
	t_stack	*previous;
	int		i;

	rt = malloc(sizeof(t_stack));
	if (!rt)
		return (NULL);
	rt->nb = args[0];
	current = rt;
	i = 0;
	while (++i < argssize)
	{
		current->next = malloc(sizeof(t_stack));
		if (!current->next)
			return (free_lists_rtptr(rt, NULL, NULL));
		previous = current;
		current = current->next;
		current->nb = args[i];
		current->prev = previous;
	}
	current->next = NULL;
	rt->prev = current;
	return (rt);
}

void	replace_value_with_index(int *a, int *a_cpy, int a_size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < a_size)
	{
		j = 0;
		while (a[i] != a_cpy[j])
			j++;
		a[i] = j;
	}
}

void	*free_lists_rtptr(t_stack *l1, t_stack *l2, void *rt)
{
	while (l1 && l1->next)
	{
		l1 = l1->next;
		free(l1->prev);
	}
	free(l1);
	while (l2 && l2->next)
	{
		l2 = l2->next;
		free(l2->prev);
	}
	free(l2);
	return (rt);
}

int	free_lists_rtint(t_stack *l1, t_stack *l2, int rt)
{
	while (l1 && l1->next)
	{
		l1 = l1->next;
		free(l1->prev);
	}
	free(l1);
	while (l2 && l2->next)
	{
		l2 = l2->next;
		free(l2->prev);
	}
	free(l2);
	return (rt);
}

t_stack	*copy_list(t_stack *a)
{
	t_stack	*rt;
	t_stack	*curr;
	t_stack	*prev;

	rt = malloc(sizeof(t_stack));
	if (!rt || !a)
		return (rtptr_free(NULL, rt));
	curr = rt;
	while (a)
	{
		curr->nb = a->nb;
		curr->prev = prev;
		a = a->next;
		if (!a)
			break ;
		prev = curr;
		curr->next = malloc(sizeof(t_stack));
		if (!(curr->next))
			return (free_lists_rtptr(rt, NULL, NULL));
		curr = curr->next;
	}
	curr->next = NULL;
	rt->prev = curr;
	return (rt);
}
