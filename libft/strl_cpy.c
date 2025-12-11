/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strl_cpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:40:05 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:57:21 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	str_n_cpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest < src && dest)
	{
		i = -1;
		while (src[++i] && i < n)
			dest[i] = src[i];
		if (i >= n)
			i = n - 1;
		dest[i] = 0;
		return ;
	}
	while (src[i])
		i++;
	if (i >= n)
		i = n - 1;
	dest[i] = 0;
	while (--i + 1)
		dest[i] = src[i];
}

int	strl_cpy(char *dest, const char *src, size_t size)
{
	size_t	rt;

	if (!size)
		return (str_len(src));
	if (!dest || !src)
		return (-1);
	rt = str_len(src);
	str_n_cpy(dest, src, size);
	if (dest == src)
		return (size - 1);
	return (rt);
}
