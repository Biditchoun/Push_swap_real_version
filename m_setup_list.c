/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:17:48 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/11 21:17:30 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	*rtptr_free_list(void *rt, t_stack *a)
{
	t_stack	*curr;
	t_stack	*prev;

	if (!a)
		return (rt);
	curr = a->next;
	prev = a;
	while (curr && curr != a)
	{
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	free(prev);
	return (rt);
}

int	rtint_free_list(int rt, t_stack *a)
{
	t_stack	*curr;
	t_stack	*prev;

	if (!a)
		return (rt);
	curr = a->next;
	prev = a;
	while (curr && curr != a)
	{
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	free(prev);
	return (rt);
}

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
			return (rtptr_free_list(NULL, rt));
		previous = current;
		current = current->next;
		current->nb = args[i];
		current->prev = previous;
	}
	current->next = NULL;
	rt->prev = current;
	return (rt);
}

/*
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
			return (rtptr_free_list(NULL, rt));
		curr = curr->next;
	}
	curr->next = NULL;
	rt->prev = curr;
	return (rt);
}*/
