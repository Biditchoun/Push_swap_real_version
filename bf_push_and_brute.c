/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_push_and_brute.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 19:56:29 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/02/08 16:14:14 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*add_pb_in_front(int *instructs, int pb_amount)
{
	int	i;
	int	j;
	int	*rt;

	i = 0;
	while (instructs[i] > -1)
		i++;
	rt = malloc(sizeof(int) * (i + pb_amount + 1));
	if (!rt)
		return (NULL);
	i = -1;
	while (pb_amount--)
		rt[++i] = 1;
	j = -1;
	while (instructs[++j] > -1)
		rt[++i] = instructs[j];
	rt[++i] = -1;
	free(instructs);
	return (rt);
}

int	*push_and_brute(t_stack **a, t_stack **b, int pb_amount)
{
	int	*instructs;

	pb_amount += pb(a, b);
	instructs = bruteforce(a, b, INT_MAX, pb_amount);
	if (!instructs && pb_amount < 6)
		return (push_and_brute(a, b, pb_amount));
	if (instructs)
		instructs = add_pb_in_front(instructs, pb_amount);
	while (pb_amount--)
		pa(a, b);
	return (instructs);
}

int	*brute_push_and_brute(t_stack **a, t_stack **b, int a_size)
{
	int	*instructs;

	if (a_size < 6)
		return (NULL);
	instructs = bruteforce(a, b, INT_MAX, 1);
	if (!instructs)
	{
		pb(a, b);
		instructs = push_and_brute(a, b, 1);
	}
	return (instructs);
}
