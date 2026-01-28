/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_brute_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:37:14 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/28 18:36:45 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_biggest_gap(t_stack **a, int **biggest_gap, int max_nb, int a_size)
{
	t_stack	*nb1;
	t_stack	*nb2;
	int		nb1_index;
	int		nb2_index;

	biggest_gap[0][0] = -42;
	biggest_gap[0][1] = -42;
	biggest_gap[1][0] = 0;
	biggest_gap[1][1] = 0;
	nb1_index = 0;
	nb2_index = 0;
	nb1 = *a;
	while (nb1)
	{
		while (nb1 && nb1->nb < max_nb && ++nb1_index)
			nb1 = nb1->next;
		if (!nb1)
			break ;
		nb2 = nb1;
		nb2_index = nb1_index;
		while (nb2 && nb2->nb >= max_nb && ++nb2_index)
			nb2 = nb2->next;
		if (nb2_index - nb1_index > biggest_gap[1][1] - biggest_gap[1][0])
		{
			biggest_gap[0][0] = nb1->nb;
			biggest_gap[0][1] = nb2->nb;
			biggest_gap[1][0] = nb1_index;
			biggest_gap[1][1] = nb2_index;
		}
		nb1 = nb1->next;
		while (nb1 && nb1->nb >= max_nb && ++nb1_index)
			nb1 = nb1->next;
	}
	if (a_size / 2 - biggest_gap[1][0] > biggest_gap[1][1] - a_size / 2)
		return (0);
	return (1);
}

int	push_two_chunks_to_b(t_bc *par, int i, int chunk_nb)
{
	int	biggest_gap_nb[2][2];
	int	nb1_max;
	int	nb2_max;
	int	to_move;
	int	ra_or_rra;
	
	nb1_max = par->chunk_size * chunk_nb;
	nb2_max = nb1_max;
	if (par->nb_amount > par->chunk_size * (chunk_nb + 1)) 
		nb2_max = par->chunk_size * (chunk_nb + 1);
	to_move = par->chunk_size * 2;
	if (nb1_max == nb2_max)
		to_move = par->chunk_size;
	ra_or_rra = find_biggest_gap(par->a, biggest_gap_nb, nb2_max, par->a_size);
	while (to_move--)
	{
		while ((*par->a)->nb > nb2_max)
		{
			if (!ra_or_rra)
				par->instructs[i++] = ra(par->a, par->b);
			else
				par->instructs[i++] = rra(par->a, par->b);
		}
		if (biggest_gap_nb[0][0] == (*par->a)->nb || biggest_gap_nb[0][1] == (*par->a)->nb)
			ra_or_rra -= 1;
		par->instructs[i++] = pb(par->a, par->b);
		par->a_size--;
		if ((*par->b)->nb > nb1_max && (*par->b)->next)
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
	while (par->nb_amount > par->chunk_size * ++chunk_nb)
		i = push_two_chunks_to_b(par, i, chunk_nb++);
	while (par->a_size-- > 5)
	{
		if ((*par->a)->nb < par->nb_amount - 5)
			par->instructs[i++] = pb(par->a, par->b);
		else
			par->instructs[i++] = ra(par->a, par->b);
	}
	return (i);
}

int	push_all_to_a(t_bc *par, int i)
{
	(void)par;
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
	i = 1;
	while (a_size / i > 5)
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
		while (i - 1 && a_size / (i - 1) == a_size / i)
			i++;
	}
}
