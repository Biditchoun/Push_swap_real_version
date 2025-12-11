/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_dup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 15:37:37 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:36:17 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*str_dup(const char *s)
{
	char	*rt;
	int		i;

	if (!s)
		return (NULL);
	i = str_len(s);
	rt = malloc(i + 1);
	if (!rt)
		return (NULL);
	strl_cpy(rt, s, i + 1);
	return (rt);
}
