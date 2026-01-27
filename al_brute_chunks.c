/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_brute_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:37:14 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/27 07:57:36 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_chunk_to_b(t_stack **a, t_stack **b, int *instructs, int max_nb)
{
	(void)(a);
	(void)(b);
	(void)(instructs);
	(void)(max_nb);
	return (0);
}

int	push_all_to_b(t_stack **a, t_stack **b, int chunk_size, int *instructs)
{
	int		a_size;
	int		i;
	int		rt;
	t_stack	*curr;

	curr = *a;
	a_size = 0;
	while (curr && ++a_size)
		curr = curr->next;
	i = 0;
	rt = 0;
	while (a_size > chunk_size * ++i)
		rt += push_chunk_to_b(a, b, instructs, chunk_size * i);
	a_size = -5;
	while (curr && ++a_size > -5)
		curr = curr->next;
	if (a_size > 0 && i--)
		rt += push_chunk_to_b(a, b, instructs, chunk_size * i + a_size);
	return (rt);
}

int	push_all_to_a(t_stack **a, t_stack **b, int *instructs, int i)
{
	(void)a;
	(void)b;
	(void)instructs;
	return (i);
}

int	*brute_chunk(t_stack **a, int chunk_size, void **f_instructs)
{
	t_stack	*a_cp[1];
	t_stack	*b_cp[1];
	int		rt[111111];
	int		*bruteforce_rt;
	int		i;

	(*a_cp) = copy_list(*a);
	if (!*a_cp)
		return (NULL);
	(*b_cp) = NULL;
	i = push_all_to_b(a_cp, b_cp, chunk_size, rt);
	bruteforce_rt = bruteforce(a_cp, b_cp, INT_MAX - 1, 0);
	i += arr_cpy(&rt[i], bruteforce_rt, INT_MAX, -1);
	apply_instructs(a_cp, b_cp, bruteforce_rt, f_instructs);
	free(bruteforce_rt);
	i = push_all_to_a(a_cp, b_cp, rt, i);
i = 0;
	rt[i] = -1;
	rtptr_free_list(NULL, *a_cp);
	return (arr_dup(rt, i + 1));
}

void	brute_chunks(t_stack **a, t_algo *info, int a_size)
{
	static void	*f_instructs[12] = {&pa, &pb, &sa, &sb, &ss,
		&ra, &rb, &rr, &rra, &rrb, &rrr, NULL};
	int			i;
	int			*buff;
	int			buff_size;

	info->curr_instructs = NULL;
	info->curr_moves = INT_MAX;
	i = 1;
	while (a_size / i > 5)
	{
		buff = brute_chunk(a, a_size / i, f_instructs);
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
