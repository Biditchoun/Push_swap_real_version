/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_get_next_try.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 20:14:34 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/23 23:07:38 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_pushes(int *instructs)
{
	int	nb_pa;
	int	nb_pb;
	int	i;

	nb_pa = 0;
	nb_pb = 0;
	i = -1;
	while (instructs[++i] > -1)
	{
		if (instructs[i] == 0)
			nb_pa++;
		else if (instructs[i] == 1)
			nb_pb++;
		if (nb_pa > nb_pb)
			break ;
	}
	if (nb_pa == nb_pb)
		return (0);
	if (nb_pb > nb_pa && --i > -1)
		while (instructs[i] == 10)
			i--;
	instructs[i]++;
	while (instructs[++i] > -1)
		instructs[i] = 0;
	return (1);
}

void	get_next_valid_instructs(int *instructs, int amount, t_stack **a)
{
	(void)a;
	(void)amount;
	if (check_pushes(instructs))
		get_next_valid_instructs(instructs, amount, a);
}

void	get_next_try(int *instructs, int amount, t_stack **a)
{
	int	i;

	i = 0;
	while (instructs[i] > -1)
		i++;
	i--;
	while (i > -1 && instructs[i] == 10)
		i--;
	if (i < 0)
	{
		while (instructs[++i] > -1)
			instructs[i] = 0;
		instructs[i] = 0;
		if (i < BRUTEFORCE)
			instructs[i + 1] = -1;
	}
	else
	{
		instructs[i]++;
		while (instructs[++i] > -1)
			instructs[i] = 0;
	}
	get_next_valid_instructs(instructs, amount, a);
}
