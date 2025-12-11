/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:00:41 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/04 15:02:54 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*arr_dup(int *arr, int size)
{
	int	*rt;
	int	i;

	if (!arr)
		return (NULL);
	rt = malloc(sizeof(int) * size);
	if (!rt)
		return (NULL);
	i = -1;
	while (++i < size)
		rt[i] = arr[i];
	return (rt);
}
