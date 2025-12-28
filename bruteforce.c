/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/28 22:08:31 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_brutesorted(t_stack *a_cpy, int amount)
{
	int		max;

	max = -1;
	while (amount-- && a_cpy)
	{
		if (max > a_cpy->nb)
			return (0);
		max = a_cpy->nb;
		a_cpy = a_cpy->next;
	}
	return (1);
}

void	get_fpointers(void **f_instructs)
{
	f_instructs[0] = &pa;
	f_instructs[1] = &pb;
	f_instructs[2] = &sa;
	f_instructs[3] = &sb;
	f_instructs[4] = &ss;
	f_instructs[5] = &ra;
	f_instructs[6] = &rb;
	f_instructs[7] = &rr;
	f_instructs[8] = &rra;
	f_instructs[9] = &rrb;
	f_instructs[10] = &rrr;
	f_instructs[11] = NULL;
}

int	apply_instructs(t_stack **a, t_stack **b, int *instructs, int fd)
{
	void	*f_instructs[12];
	int		(*f)(t_stack **, t_stack **, int);
	int		i;

	get_fpointers(f_instructs);
	i = -1;
	while (instructs[++i] > -1)
	{
		f = f_instructs[instructs[i]];
		f(a, b, fd);
	}
	return (i);
}

void	undo_changes(t_stack **a_cpy, t_stack **b_cpy,
		int *instructs, void **f_instructs)
{
	int	(*f)(t_stack **, t_stack **, int);
	int	i;

	i = 0;
	while (instructs[i] > -1)
		i++;
	while (--i > -1)
	{
		if (instructs[i] == 0)
			f = f_instructs[1];
		else if (instructs[i] == 1)
			f = f_instructs[0];
		else if (instructs[i] >= 2 && instructs[i] <= 4)
			f = f_instructs[instructs[i]];
		else if (instructs[i] >= 5 && instructs[i] <= 7)
			f = f_instructs[instructs[i] + 3];
		else if (instructs[i] >= 8 && instructs[i] <= 10)
			f = f_instructs[instructs[i] - 3];
		f(a_cpy, b_cpy, 66);
	}
}

int	bruteforce(t_stack **a, t_stack **b, int amount, int fd)
{
	int		instructs[BRUTEFORCE + 2];
	void	*f_instructs[12];
	t_stack	*a_cpy;
	t_stack	*b_cpy;
	int		rt;

	get_fpointers(f_instructs);
	instructs[BRUTEFORCE] = -1;
	instructs[0] = -1;
	rt = 0;
	a_cpy = copy_list(*a);
	b_cpy = copy_list(*b);
	if ((*a && !a_cpy) || (*b && !b_cpy))
		return (free_lists_rtint(a_cpy, b_cpy, 0));
	while (instructs[BRUTEFORCE] < 0)
	{
#include <stdio.h>
int i = -1;
while (instructs[++i] > -1)
	printf("%i ", instructs[i]);
printf("\n");
		get_next_try(instructs, amount, a);
		apply_instructs(&a_cpy, &b_cpy, instructs, 66);
		if (check_if_brutesorted(a_cpy, amount))
			rt = apply_instructs(a, b, instructs, fd);
		if (rt)
			return (free_lists_rtint(a_cpy, b_cpy, rt));
		undo_changes(&a_cpy, &b_cpy, instructs, f_instructs);
	}
	return (free_lists_rtint(a_cpy, b_cpy, 0));
}
