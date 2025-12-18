/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/18 18:46:31 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	conclude_bruteforce(t_stack **a, t_stack **b, int *instructs, int fd)
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

int	bruteforce(t_stack **a, t_stack **b, int amount, int fd)
{
	int		instructs[BRUTEFORCE + 1];
	void	*f_instructs[12];
	t_stack	*a_cpy;
	t_stack	*b_cpy;
	int		rt;

	get_fpointers(f_instructs);
	instructs[BRUTEFORCE] = -1;
	instructs[0] = -1;
	rt = 0;
	while (instructs[BRUTEFORCE] < 0)
	{
		a_cpy = copy_list(*a);
		b_cpy = copy_list(*b);
		if ((a && !a_cpy) || (b && !b_cpy))
			return (free_lists_rtint(a_cpy, b_cpy, 0));
		get_next_try(instructs);
		apply_instructs(&a_cpy, &b_cpy, instructs, f_instructs);
		if (check_if_brutesorted(*a, a_cpy, amount))
			rt = conclude_bruteforce(a, b, instructs, fd);
		free_lists_rtptr(a_cpy, b_cpy, NULL);
		if (rt)
			return (rt);
	}
	return (0);
}
