/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   albc_brute_chunks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:37:14 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/02/17 09:16:32 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*determine_rotation(t_bc *par, int amount_in_a, int b_size)
{
}

bool	check_if_all_at_top(t_stack *b, int amount_in_a, int b_size)
{
}

int	get_next_five_to_top(t_bc *par, int i, int *amount_in_a, int *b_size)
{
	int	(*rb_or_rrb)(t_stack **a, t_stack **b);

	ra_or_rra = &ra;
	while (rb_or_rrb)
	{
		rb_or_rrb = determine_rotation(par, *amount_in_a, *b_size);
		while ((*par->b)->nb < *b_size - 5)
			par->instructs[i++] = rb_or_rrb(par->a, par->b);
		if (!check_if_all_at_top((*par->b), *amount_in_a, *b_size))
			while ((*par->b) >= *b_size - 5 && ++(*amount_in_a))
				par->instructs[i++] = pa(par->a, par->b);
	}
	return (i);
}

int	push_all_to_a(t_bc *par, int i, int b_size)
{
	int	amount_in_a;
	int	*bruteforce_rt;

	while (*par->b)
	{
		amount_in_a = 0;
		i = get_next_five_to_top(par, i, &amount_in_a, &b_size);
		bruteforce_rt = bruteforce(par->a, par->b, amount_in_a, 5 - amount_in_a);
		if (!bruteforce_rt)
			return (0);
		i += arr_cpy(&par->instructs[i], bruteforce_rt, INT_MAX, -1);
		apply_instructs(par->a, par->b, bruteforce_rt, par->f_instructs);
		free(bruteforce_rt);
		b_size = b_size - 5 + amount_in_a;
	}
	return (i);
}

int	*brute_chunk(t_stack **a, int chunk_size, int a_size)
{
	t_bc		par;
	static void	*f_instructs[] = {&pa, &pb, &sa, &sb, &ss,
		&ra, &rb, &rr, &rra, &rrb, &rrr, NULL};
	int			i;
	int			*bruteforce_rt;

	*par.a = copy_list(*a);
	if (!*a)
		return (NULL);
	*par.b = NULL;
	par.f_instructs = f_instructs;
	par.chunk_size = chunk_size;
	par.nb_amount = a_size;
	par.a_size = a_size;
	i = push_all_to_b(&par);
	bruteforce_rt = bruteforce(par.a, par.b, INT_MAX - 1, 0);
	if (!bruteforce_rt)
		return (NULL);
	i += arr_cpy(&par.instructs[i], bruteforce_rt, INT_MAX, -1);
	apply_instructs(par.a, par.b, bruteforce_rt, par.f_instructs);
	free(bruteforce_rt);
	i = push_all_to_a(&par, i, par.nb_amount - par.a_size);
	par.instructs[i] = -1;
	rtptr_free_list(NULL, *par.a);
	return (arr_dup(par.instructs, i + 1));
}

void	brute_chunks(t_stack **a, t_algo *info, int a_size)
{
	int	i;
	int	*buff;
	int	buff_size;

	info->curr_instructs = NULL;
	info->curr_moves = INT_MAX;
	i = 0;
	while (a_size / ++i > 1)
	{
		buff = brute_chunk(a, a_size / i, a_size);
		buff = clean_instructs(buff);
		buff_size = arr_len(buff, -1);
		if (buff_size < info->curr_moves && buff_size > 0)
		{
			free(info->curr_instructs);
			info->curr_instructs = buff;
			info->curr_moves = buff_size;
		}
		else
			free(buff);
		while (a_size / i == a_size / (i + 1))
			i++;
	}
}
