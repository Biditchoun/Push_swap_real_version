/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:55:22 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 17:57:17 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_arr(int *arr, int arrsize)
{
	int	i;

	i = -1;
	while (++i < arrsize)
		ft_printf("%i ", arr[i]);
	write(1, "\n", 1);
}
