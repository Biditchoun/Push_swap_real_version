/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:47:52 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/12 20:08:46 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
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
*/
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

int	do_the_magic(t_stack *a, t_stack *b)
{
	t_stack	*last_a;
	t_stack	*last_b;

	last_a = a;
	while (last_a->next)
		last_a = last_a->next;
	last_b = NULL;
	return (0);
}

int	main(int ac, char **av)
{
	int		argssize;
	int		*args;
	t_stack	*a;
	t_stack	*b;

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
	b = NULL;
	do_the_magic(a, b);
	free_list_rtptr(a, NULL);
	return (0);
}
