/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 15:53:47 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:20:57 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	strn_cmp(const char *s1, const char *s2, size_t n)
{
	int	i;

	if (!n)
		return (0);
	if (!s1 || !s2)
		return (-1);
	i = -1;
	while (n-- && (s1[++i] || s2[i]))
		if (s1[i] != s2[i])
			break ;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
