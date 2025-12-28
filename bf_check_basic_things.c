/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_check_basic_things.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 20:50:16 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/28 22:29:20 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_nb_pushes(int *instructs)
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
	return (increment_and_fill(instructs, i));
}

int	check_pushes_proximity(int *instructs)
{
	int	i;

	i = -1;
	while (instructs[++i] > -1)
	{
		if (instructs[i] == 0 && instructs[i + 1] == 1)
			break ;
		if (instructs[i] == 1 && instructs[i + 1] == 0)
			break ;
	}
	if (instructs[i] == -1)
		return (0);
	return (increment_and_fill(instructs, i + 1));
}

int	check_b_actions(int *instructs)
{
	int	i;
	int	b_size;

	b_size = 0;
	i = -1;
	while (instructs[++i] > -1)
	{
		if (instructs[i] == 0)
			b_size--;
		else if (instructs[i] == 1)
			b_size++;
		else if (b_size < 2 && instructs[i] != 2 && instructs[i] != 5 && instructs[i] != 8)
			break ;
		else if (b_size == 2 && (instructs[i] == 6 || instructs[i] == 7 || instructs[i] == 9 || instructs[i] == 10))
			break ;
	}
	if (instructs[i] == -1)
		return (0);
	return (increment_and_fill(instructs, i));
}
