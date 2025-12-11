/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_toa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:36:00 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:44:20 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_rt(char *rt, int sign, int size, long nn)
{
	rt[sign + size] = 0;
	while (--size > -1)
	{
		rt[sign + size] = nn % 10 + '0';
		nn /= 10;
	}
	if (sign)
		rt[0] = '-';
}

char	*i_toa(int n)
{
	char	*rt;
	long	nn;
	int		sign;
	int		size;

	if (!n)
		return (str_dup("0"));
	sign = 0;
	if (n < 0)
		sign = 1;
	size = 0;
	nn = n;
	nn *= (1 - 2 * sign);
	while (n && size++ > -1)
		n /= 10;
	rt = malloc(sign + size + 1);
	if (!rt)
		return (NULL);
	write_rt(rt, sign, size, nn);
	return (rt);
}
