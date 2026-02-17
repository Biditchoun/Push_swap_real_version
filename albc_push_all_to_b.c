/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   albc_push_all_to_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/17 08:11:40 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/02/17 08:28:09 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	determine_nb_limit(t_stack *a, int ra_amount, int nb_max, int gap_size)
{
	t_stack	*comp;
	int		dist_from_end;

	comp = a;
	dist_from_end = 0;
	a = a->next;
	while (a)
	{
		if (a->nb >= nb_max)
			ra_amount--;
		a = a->next;
		dist_from_end++;
	}
	if (ra_amount - dist_from_end + gap_size > 0 && comp->next)
		return (comp->nb);
	return (-2);
}

void	*i_am_norminette_friendly(int nb_limit, int comp_nb)
{
	if (nb_limit == comp_nb)
		return (&rra);
	return (&ra);
}

void	*find_biggest_gap(t_stack *a, int nb_max, int *nb_limit, int gap_size)
{
	t_stack	*comp;
	int		curr_gap_size;
	void	*ra_or_rra;
	int		ra_amount;

	ra_or_rra = &ra;
	ra_amount = 0;
	while (a)
	{
		while (a && a->nb < nb_max)
			a = a->next;
		curr_gap_size = 0;
		comp = a;
		while (a && comp->next && comp->next->nb >= nb_max && ++curr_gap_size)
			comp = comp->next;
		if (curr_gap_size + 1 > gap_size)
		{
			gap_size = curr_gap_size + 1;
			*nb_limit = determine_nb_limit(comp, ra_amount, nb_max, gap_size);
			ra_or_rra = i_am_norminette_friendly(*nb_limit, comp->nb);
		}
		while (a && a->nb >= nb_max && ++ra_amount)
			a = a->next;
	}
	return (ra_or_rra);
}

int	push_two_chunks_to_b(t_bc *par, int i, int chunk_nb)
{
	int	nb1_max;
	int	nb2_max;
	int	to_move;
	int	(*ra_or_rra)(t_stack **a, t_stack **b);
	int	ra_or_rra_limit;

	nb1_max = min(par->chunk_size * chunk_nb, par->nb_amount - 6);
	nb2_max = min(par->chunk_size * (chunk_nb + 1), par->nb_amount - 6);
	to_move = nb2_max - (par->chunk_size * (chunk_nb - 1));
	ra_or_rra_limit = -1;
	while (to_move--)
	{
		while ((*par->a)->nb >= nb2_max || ra_or_rra_limit == -1)
		{
			if ((*par->a)->nb == ra_or_rra_limit || ra_or_rra_limit == -1)
				ra_or_rra = find_biggest_gap(*(par->a), nb2_max,
						&ra_or_rra_limit, 0);
			if ((*par->a)->nb >= nb2_max && (*par->a)->nb != ra_or_rra_limit)
				par->instructs[i++] = ra_or_rra(par->a, par->b);
		}
		par->instructs[i++] = pb(par->a, par->b);
		if (par->a_size-- && (*par->b)->nb >= nb1_max && (*par->b)->next)
			par->instructs[i++] = rb(par->a, par->b);
	}
	return (i);
}

int	push_all_to_b(t_bc *par)
{
	int	chunk_nb;
	int	i;

	chunk_nb = 1;
	i = 0;
	while (par->a_size > 6)
	{
		i = push_two_chunks_to_b(par, i, chunk_nb);
/*		ft_printf("Chunk size : %i\nChunk nb : %i\n", par->chunk_size, chunk_nb);
		check_list(*par->a);
		check_list(*par->b);
		int j = -1;
		while (++j < i)
			ft_printf("%i ", par->instructs[j]);
		ft_printf("\n");
*/
		chunk_nb += 2;
	}
	return (i);
}
