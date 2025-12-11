/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 11:47:52 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/11 18:38:18 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_list(t_stack *a)
{
#include <stdio.h>
	while (a)
	{
		printf("%i : %p\n%p %p\n", a->nb, a, a->prev, a->next);
		a = a->next;
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
	rt = convert_to_lists(args, argssize);
	return (rt);
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
	sa(&a);
	print_list(a);
	printf("\n");
	sa(&a);
	print_list(a);
	free_list_rtptr(a, NULL);
	return (0);
}
