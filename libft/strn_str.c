/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:38:30 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:32:13 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (!big || !little | len)
		return (-1);
	if (!little[0])
		return (0);
	i = -1;
	while (++i < len && big[i])
	{
		j = 0;
		while (big[i + j] == little[j] && i + j < len && little[j])
			j++;
		if (!little[j])
			return (i);
	}
	return (-1);
}
