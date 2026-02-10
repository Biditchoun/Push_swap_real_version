/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   albc_brute_chunks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:37:14 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/02/10 23:33:31 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest_gap(t_stack *a, int a_size, int nb_max, int *nb_limit)
{
	t_stack	*comp;
	int		i;
	int		j;
	int		gap_size;
	int		ra_or_rra;
	
	*nb_limit = -1;
	ra_or_rra = 0;
	gap_size = 0;
	i = 0;
	while (a)
	{
		while (a && a->nb < nb_max && ++i)
			a = a->next;
		if (!a)
			return (ra_or_rra);
		j = i;
		comp = a;
		while (comp->next && comp->next->nb >= nb_max && ++j)
			comp = comp->next;
		if (j - i > gap_size)
		{
			gap_size = j - i + 1;
			ra_or_rra = 0;
			*nb_limit = a->nb;
//This condition needs fixing
			if (gap_size > a_size - j)
			{
				ra_or_rra = 1;
				*nb_limit = comp->nb;
			}
		}
		while (a && a->nb >= nb_max && ++i)
			a = a->next;
	}
	return (ra_or_rra);
}

int	push_two_chunks_to_b(t_bc *par, int i, int chunk_nb)
{
	int	nb1_max;
	int	nb2_max;
	int	to_move;
	int	ra_or_rra;
	int	ra_or_rra_limit;
	
	nb1_max = min(par->chunk_size * chunk_nb, par->nb_amount - 6);
	nb2_max = min(par->chunk_size * (chunk_nb + 1), par->nb_amount - 6);
	to_move = nb2_max - (par->chunk_size * (chunk_nb - 1));
	ra_or_rra = find_biggest_gap(*(par->a), par->a_size, nb2_max, &ra_or_rra_limit);
	while (to_move--)
	{
		while ((*par->a)->nb >= nb2_max)
		{
			if ((*par->a)->nb == ra_or_rra_limit)
				ra_or_rra = find_biggest_gap(*(par->a), par->a_size, nb2_max, &ra_or_rra_limit);
			if (!ra_or_rra)
				par->instructs[i++] = ra(par->a, par->b);
			else
				par->instructs[i++] = rra(par->a, par->b);
		}
		par->instructs[i++] = pb(par->a, par->b);
		par->a_size--;
		if ((*par->b)->nb >= nb1_max && (*par->b)->next)
			par->instructs[i++] = rb(par->a, par->b);
	}
	return (i);
}

int	push_all_to_b(t_bc *par)
{
	int	chunk_nb;
	int	i;

	chunk_nb = 0;
	i = 0;
	while (par->a_size > 6 && ++chunk_nb)
		i = push_two_chunks_to_b(par, i, chunk_nb++);
	par->a_size++;
	return (i);
}

int	push_all_to_a(t_bc *par, int i)
{
	while (*(par->b) && par->a_size++ > -1)
		par->instructs[i++] = pa(par->a, par->b);
	return (i);
}

int	*brute_chunk(t_stack **a, int chunk_size, int a_size)
{
	t_bc		par;
	static void	*f_instructs[] = {&pa, &pb, &sa, &sb, &ss, &ra, &rb, &rr, &rra, &rrb, &rrr, NULL};
	int			i;

	*par.a = copy_list(*a);
	if (!*a)
		return (NULL);
	*par.b = NULL;
	par.f_instructs = f_instructs;
	par.chunk_size = chunk_size;
	par.nb_amount = a_size;
	par.a_size = a_size;
	i = push_all_to_b(&par);
	par.bruteforce_rt = bruteforce(par.a, par.b, INT_MAX - 1, 0);
	i += arr_cpy(&par.instructs[i], par.bruteforce_rt, INT_MAX, -1);
	apply_instructs(par.a, par.b, par.bruteforce_rt, par.f_instructs);
	free(par.bruteforce_rt);
	i = push_all_to_a(&par, i);
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
		if (buff_size < info->curr_moves)
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
