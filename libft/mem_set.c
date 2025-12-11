/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 17:48:24 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:06:00 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*mem_set(void *s, int c, size_t n)
{
	char	*p;
	int		i;

	if (!n)
		return (s);
	if (!s)
		return (NULL);
	p = (char *)s;
	i = 0;
	while (n-- > 0)
		p[i++] = c;
	return (s);
}
