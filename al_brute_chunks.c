/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_brute_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:37:14 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/22 21:47:41 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_all_to_b(t_stack **a, t_stack **b, int chunk_size, int *instructs)
{
	int	i;

	i = 0;
}

int	*brute_chunk(t_stack **a, t_stack **b, int chunk_size)
{
	int	rt[111111];
	int	i;
	int	j;

	i = push_all_to_b(a, b, chunk_size, rt);
	bruteforce_rt = bruteforce(a, b, 6, 0);
	if (bruteforce_rt)
	{
		j = -1;
		while (bruteforce_rt[++j] > -1)
			rt[i++] = bruteforce_rt[j];
		free(bruteforce_rt);
	}
	i = push_all_to_a(a, b, rt, i)
	rt[i] = -1;
	return (arr_dup(rt, i));
}

void	brute_chunks(t_stack **a, t_stack **b, t_algo *info, int a_size)
{
	int	i;
	int	*buff;
	int	buff_size;

	if (BRUTEFORCE < 10)
		aled;
	info->curr_instructs = NULL;
	info->curr_moves = INT_MAX;
	i = 0;
	while (a_size / ++i > 5)
	{
		buff = brute_chunk(a, b, a_size / i);
		buff = clean_instructs(buff);
		buff_size = arr_len(buff, -1);
		if (buff_size < info->curr_moves)
		{
			free(info->curr_instructs);
			info->curr_instructs = buff;
			info->curr_moves = buff_size;
		}
		else
			free(buff);
	}
}
