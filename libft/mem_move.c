/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_move.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:57:30 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:36:37 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*mem_move(void *dest, const void *src, size_t n)
{
	char	*pd;
	char	*ps;

	if ((dest == src && dest) || !n)
		return (dest);
	if (!dest || !src)
		return (NULL);
	if (dest < src)
		return (mem_cpy(dest, src, n));
	pd = (char *)dest;
	ps = (char *)src;
	while (n-- > 0)
		pd[n] = ps[n];
	return (dest);
}
