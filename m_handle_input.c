/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:15:14 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/11 16:40:29 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_argssize(int ac, char **av)
{
	int		rt;
	int		i;

	rt = 0;
	while (--ac)
	{
		i = 0;
		while (av[ac][i])
		{
			while (av[ac][i] && av[ac][i] == ' ')
				i++;
			if (av[ac][i] && str_chr("+-0123456789", av[ac][i]) == -1)
				return (0);
			if (av[ac][i] == '-' || av[ac][i] == '+')
				i++;
			if (av[ac][i] && str_chr("0123456789", av[ac][i]) > -1)
				rt++;
			while (av[ac][i] && str_chr("0123456789", av[ac][i]) > -1)
				i++;
			if (av[ac][i] && av[ac][i] != ' ')
				return (0);
		}
	}
	return (rt);
}

int	store_into_arr(char **av, int *args, int argssize)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			while (av[i][j] == ' ')
				j++;
			if (av[i][j])
				args[k++] = a_toi(&av[i][j]);
			if (av[i][j] && check_if_int(&av[i][j++]))
				return (-1);
			while (av[i][j] && str_chr("0123456789", av[i][j]) > -1)
				j++;
		}
	}
	if (k != argssize)
		return (-1);
	return (k);
}

int	check_duplicates(int *args, int argssize)
{
	int	i;

	i = -1;
	while (++i < argssize)
		if (i + 1 < argssize
			&& int_chr(&args[i + 1], args[i], argssize - i - 1) > -1)
			return (1);
	return (0);
}

int	*convert_to_arr(char **av, int argssize)
{
	int	*rt;

	rt = malloc(sizeof(int) * argssize);
	if (!rt)
		return (NULL);
	if (store_into_arr(av, rt, argssize) < 0)
		return (rtptr_free(NULL, rt));
	if (check_duplicates(rt, argssize))
		return (rtptr_free(NULL, rt));
	return (rt);
}

int	check_if_sorted(int *a, int a_size)
{
	int	i;

	i = -1;
	while (++i + 1 < a_size)
		if (a[i] > a[i + 1])
			return (0);
	return (1);
}
