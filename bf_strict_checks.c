/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_strict_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:26:36 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/19 00:27:38 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	continue_check_small_index(int instr, int s_id, int a_size, int b_size)
{
	if (instr >= 5 && instr <= 7)
	{
		if (s_id > 1 && instr != 6)
			s_id--;
		else if (s_id == 1 && instr != 6)
			s_id = a_size;
		else if (s_id == -1 && instr != 5)
			s_id = -b_size;
		else if (instr != 5)
			s_id++;
	}
	else if (instr >= 8)
	{
		if (s_id == a_size && instr != 9)
			s_id = 1;
		else if (s_id > 0 && instr != 9)
			s_id++;
		else if (s_id == -b_size && instr != 8)
			s_id = -1;
		else if (instr != 8)
			s_id--;
	}
	return (s_id);
}

int	check_smallest_index(int *instrs, int s_id, int a_size, int b_size)
{
	while (*instrs > -1)
	{
		if (*instrs <= 1)
		{
			a_size += 1 - 2 * *instrs;
			b_size += -1 + 2 * *instrs;
			if (s_id != -1 + 2 * *instrs)
				s_id += 1 - 2 * *instrs;
			else
				s_id = 1 - 2 * *instrs;
		}
		else if (*instrs >= 2 && *instrs <= 4 && s_id >= -2 && s_id <= 2)
		{
			if ((s_id == 1 && *instrs != 3) || (s_id == -2 && *instrs != 2))
				s_id++;
			else if ((s_id == 2 && *instrs != 3)
				|| (s_id == -1 && *instrs != 3))
				s_id--;
		}
		else
			s_id = continue_check_small_index(*instrs, s_id, a_size, b_size);
		instrs++;
	}
	return (s_id - 1);
}

int	invalid_ra_count(t_bf *params, int i, int ra_count)
{
	while (ra_count-- > 0)
	{
		if (params->instructs[--i] <= 4 || params->instructs[i] == 6)
			params->instructs[i] = 7;
		else if (params->instructs[i] == 7)
			ra_count--;
		else if (params->instructs[i] == 8 || params->instructs[i] == 10)
			ra_count++;
		else if (params->instructs[i] == 5 && ra_count--)
			params->instructs[i] = 7;
	}
	return (increment_and_fill(params->instructs, i,
			0, &params->instructs_size));
}

int	invalid_rb_count(t_bf *params, int i, int ra_count, int rb_count)
{
	if (ra_count)
		return (invalid_ra_count(params, i, ra_count));
	while (rb_count-- > 0)
	{
		if (params->instructs[--i] <= 5)
			params->instructs[i] = 8;
		else if (params->instructs[i] <= 7)
		{
			params->instructs[i] = 7;
			if (rb_count--)
				params->instructs[i]++;
		}
		else if (params->instructs[i] >= 9)
			rb_count++;
	}
	return (increment_and_fill(params->instructs, i,
			0, &params->instructs_size));
}

int	strict_checks(t_bf *params, int rt)
{
	int	ra_count;
	int	rb_count;
	int	i;

	ra_count = 0;
	rb_count = 0;
	i = -1;
	while (params->instructs[++i] > -1)
	{
		if (params->instructs[i] == 5 || params->instructs[i] == 7)
			ra_count++;
		if (params->instructs[i] == 6 || params->instructs[i] == 7)
			rb_count++;
		if (params->instructs[i] == 8 || params->instructs[i] == 10)
			ra_count--;
		if (params->instructs[i] == 9 || params->instructs[i] == 10)
			rb_count--;
		if (ra_count < 0 || rb_count < 0)
			return (increment_and_fill(params->instructs, i,
					0, &params->instructs_size));
	}
	if (ra_count || rb_count)
		rt = invalid_rb_count(params, i, ra_count, rb_count);
	return (rt);
}
