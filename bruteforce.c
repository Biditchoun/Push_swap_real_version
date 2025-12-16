/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bruteforce.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 14:07:11 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/16 15:59:32 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_fpointers(t_bf *params)
{
	params->f_instructs[0] = &pa;
	params->f_instructs[1] = &pb;
	params->f_instructs[2] = &sa;
	params->f_instructs[3] = &sb;
	params->f_instructs[4] = &ss;
	params->f_instructs[5] = &ra;
	params->f_instructs[6] = &rb;
	params->f_instructs[7] = &rr;
	params->f_instructs[8] = &rra;
	params->f_instructs[9] = &rrb;
	params->f_instructs[10] = &rrr;
	params->f_instructs[11] = NULL;
	params->f_write[0] = "pa\n";
	params->f_write[1] = "pb\n";
	params->f_write[2] = "sa\n";
	params->f_write[3] = "sb\n";
	params->f_write[4] = "ss\n";
	params->f_write[5] = "ra\n";
	params->f_write[6] = "rb\n";
	params->f_write[7] = "rr\n";
	params->f_write[8] = "rra\n";
	params->f_write[9] = "rrb\n";
	params->f_write[10] = "rrr\n";
	params->f_write[11] = NULL;
}

int	conclude_bruteforce(t_stack **a, t_stack **last_a, t_bf params, int fd)
{
	t_stack	*last_a;
	t_stack	*last_b;
	int		(*f)(t_stack **, t_stack **, t_stack **, t_stack **);
	int		i;
	int		rt;

	last_a = get_last_node(*a);
	last_b = get_last_node(*b);
	rt = 0;
	i = -1;
	while (params.instructs[++i] > -1)
	{
		f = params.f_instructs[instructs[i]];
		rt += f(a, &last_a, b, &last_b);
		write(fd, params.f_write, 3);
		if (instructs[i] > 7)
			write(fd, "\n", 1);
	}
	return (rt);
}

int	bruteforce(t_stack **a, t_stack **b, int amount, int fd)
{
	t_bf	params;
	t_stack	*a_cpy;
	t_stack	*last_a_cpy;
	int		rt;

	get_fpointers(&params);
	params.amount_to_sort = amount;
	params.instructs[BRUTEFORCE] = -1;
	params.instructs[0] = -1;
	rt = 0;
	while (params.instructs[BRUTEFORCE] < 0)
	{
		a_cpy = copy_list(*a);
		last_a_cpy = get_last_node(a_cpy);
		get_next_try(params.instructs);
		apply_instructs(&a_cpy, &last_a_cpy, params, 3);
		if (check_if_sorted(*a, a_cpy, params.amount_to_sort))
			rt = conclude_bruteforce(a, b, params, fd);
		free_list_rtptr(a_cpy, NULL);
		if (rt)
			return (rt);
	}
	return (0);
}
