/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:47:52 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/16 15:59:29 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	check_list(t_stack *a, t_stack *last)
{
#include <stdio.h>
	t_stack *cp;

	if (!a)
		return ;
	cp = a->next;
	printf("%i ", a->nb);
	while (cp)
	{
		if (cp->prev != a)
			printf("wrong prev\n");
		printf("%i ", cp->nb);
		a = a->next;
		cp = cp->next;
	}
	if (last != a)
		printf("wrong last : %i\n", last->nb);
	printf("\n");
}

t_stack	*set_up_list(int *args, int argssize)
{
	int		*args_cpy;
	t_stack	*rt;

	args_cpy = arr_dup(args, argssize);
	if (!args_cpy)
		return (rtptr_free(NULL, args));
	bubble_sort(args_cpy, argssize);
	replace_value_with_index(args, args_cpy, argssize);
	free(args_cpy);
	rt = convert_to_lists(args, argssize);
	return (rt);
}

int	do_the_magic(t_stack *a, int argssize)
{
	t_stack	*a_cpy;
	t_stack	*last_a;
	t_stack	*last_a_cpy;
	t_algo	info;
//	int		i;

	last_a = get_last_node(a);
	info.curr_moves = bruteforce(&a, NULL, INT_MAX, 3);
	if (info.curr_moves)
		return (bruteforce(&a, NULL, INT_MAX, 1));
	(void)argssize;
/*	info.min_moves = INT_MAX;
	info.algo_nb = 1;
	i = 0;
	while (argssize / ++i > 1)
	{
		a_cpy = copy_list(a);
		if (!a)
			return (-1);
		last_a_cpy = get_last_node(a_cpy);
		info.curr_moves = chunk_sort(&a_cpy, &last_a_cpy, 3);
		if (info.curr_moves < info.min_moves)
		{
			info.min_moves = info.curr_moves;
			info.algo_param = i;
		}
		free_list_rtptr(a_cpy, NULL);
	}
	{instert other sorting algorithms}
	{execute best performing algorithm indicated in info}
*/	return (0);
}

int	main(int ac, char **av)
{
	int		argssize;
	int		*args;
	int		rt;
	t_stack	*a;

	if (ac == 1)
		return (0);
	argssize = check_argssize(ac, av);
	if (!argssize)
		return (write_rtint("Error\n", 1, 2));
	args = convert_to_arr(av, argssize);
	if (!args)
		return (write_rtint("Error\n", 1, 2));
	if (check_if_sorted(args, argssize))
		return (rtint_free(0, args));
	a = set_up_list(args, argssize);
	if (!a)
		return (rtint_free(-1, args));
	free(args);
	rt = do_the_magic(a, argssize);
	free_list_rtptr(a, NULL);
	return (rt);
}
