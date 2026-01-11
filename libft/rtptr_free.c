/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtptr_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 09:53:08 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/11 19:52:43 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*rtptr_free(void *rt, void *p)
{
	free(p);
	return (rt);
}

void	*rtptr_ffree(void *rt, void **p)
{
	int	i;

	i = -1;
	while (p[++i])
		free(p[i]);
	free(p);
	return (rt);
}
