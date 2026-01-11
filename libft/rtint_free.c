/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtint_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 17:05:39 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/11 19:51:44 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	rtint_free(int rt, void *p)
{
	free(p);
	return (rt);
}

int	rtint_ffree(int rt, void **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
	return (rt);
}
