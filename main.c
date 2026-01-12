/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:47:52 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/12 21:32:17 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*void	check_list(t_stack *a)
{
#include <stdio.h>
	t_stack *cp, *cp2;

	if (!a)
	{	printf("null list\n");
		return ;
	}
	cp2 = a;
	cp = a->next;
	printf("Last : %i, list : %i ", a->prev->nb, a->nb);
	while (cp != a)
	{
		if (cp->prev != cp2)
			printf("wrong prev\n");
		printf("%i ", cp->nb);
		cp2 = cp2->next;
		cp = cp->next;
	}
	printf("\n");
}
*/
void	bubble_sort(int *a, int a_size)
{
	int	i;
	int	j;
	int	buff;

	i = -1;
	while (++i < a_size)
	{
		j = i;
		while (++j < a_size)
		{
			if (a[i] > a[j])
			{
				buff = a[i];
				a[i] = a[j];
				a[j] = buff;
			}
		}
	}
}

void	print_instructs(int *instructs, int fd)
{
	static char	*print[12] = {"pa\n", "pb\n", "sa\n", "sb\n",
		"ss\n", "ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n", NULL};
	int			i;

	if (!fd)
		return ;
	i = -1;
	while (instructs[++i] > -1)
	{
		if (instructs[i] < 8)
			write(1, print[instructs[i]], 3);
		else
			write(1, print[instructs[i]], 4);
	}
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
	rt = convert_to_list(args, argssize);
	return (rt);
}

int	do_the_magic(t_stack **a, int argssize)
{
	t_stack	*b[1];
	t_algo	info;

	*b = NULL;
	if (bruteforce(a, b, INT_MAX, 1))
		return (0);
	(void)argssize;
	info.min_moves = INT_MAX;
	info.algo_nb = 1;
/*	chunck_sorts(&info, &a, &b, argssize);
	{insert other sorting algorithms}
	{execute best performing algorithm, indicated in info}*/
	return (0);
}

int	main(int ac, char **av)
{
	int		argssize;
	int		*args;
	int		rt;
	t_stack	*a[1];

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
	*a = set_up_list(args, argssize);
	if (!*a)
		return (rtint_free(-1, args));
	free(args);
	rt = do_the_magic(a, argssize);
	rtptr_free_list(NULL, *a);
	return (rt);
}
