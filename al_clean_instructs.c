/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_clean_instructs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:48:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/02/08 16:40:53 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	apply_instructs(t_stack **a, t_stack **b,
		int *instructs, void **f_instructs)
{
	int	(*f)(t_stack **, t_stack **);
	int	i;

	i = -1;
	while (instructs[++i] > -1)
	{
		f = f_instructs[instructs[i]];
		f(a, b);
	}
	return (i);
}

int	*clean_instructs(int *instructs)
{
	return (instructs);
}
