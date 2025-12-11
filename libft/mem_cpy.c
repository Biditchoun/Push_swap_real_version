/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:54:41 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:11:06 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overlap(char *pd, char *ps, size_t n)
{
	size_t	nn;
	int		i;

	nn = n;
	i = -1;
	while (nn-- > 0)
		if (pd == &ps[++i])
			break ;
	if (!nn || pd < ps)
		return (0);
	while (n-- > 0)
		pd[n] = ps[n];
	return (1);
}

void	*mem_cpy(void *dest, const void *src, size_t n)
{
	char	*pd;
	char	*ps;
	int		i;

	if (!n)
		return (dest);
	if (!dest || !src)
		return (NULL);
	pd = (char *)dest;
	ps = (char *)src;
	if (check_overlap(pd, ps, n))
		return (dest);
	i = -1;
	while (n-- > 0 && ++i > INT_MIN)
		pd[i] = ps[i];
	return (dest);
}
