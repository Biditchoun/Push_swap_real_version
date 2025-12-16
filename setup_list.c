/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:17:48 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/16 12:33:38 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*convert_to_lists(int *args, int argssize)
{
	t_stack	*rt;
	t_stack	*current;
	t_stack	*previous;
	int		i;

	rt = malloc(sizeof(t_stack));
	if (!rt)
		return (NULL);
	rt->prev = NULL;
	rt->nb = args[0];
	current = rt;
	i = 0;
	while (++i < argssize)
	{
		current->next = malloc(sizeof(t_stack));
		if (!current->next)
			return (free_list_rtptr(rt, NULL));
		previous = current;
		current = current->next;
		current->nb = args[i];
		current->prev = previous;
	}
	current->next = NULL;
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

void	bubble_sort(int *a, int a_size)
{
	int	i;
	int	j;
	int	buff;

	i = -1;
	while (++i < a_size)
	{
		j = i;
		while (++j < a_size)
		{
			if (a[i] > a[j])
			{
				buff = a[i];
				a[i] = a[j];
				a[j] = buff;
			}
		}
	}
}
