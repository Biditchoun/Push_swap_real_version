/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bf_strict_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/11 21:26:36 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/13 21:01:26 by sawijnbe         ###   ########.fr       */
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

int	strict_checks(t_bf *params, t_stack **a, int i)
{
	(void)params;
	(void)a;
	return (i);
}
