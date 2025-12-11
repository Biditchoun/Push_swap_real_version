/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:51:31 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 09:58:42 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	check_base(char *base)
{
	int	i;
	int	j;

	if (!base)
		return (0);
	i = -1;
	while (base[++i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i;
		while (base[++j])
			if (base[i] == base[j])
				return (0);
	}
	if (i < 2)
		return (0);
	return ((unsigned int) i);
}

static int	putnbrbase(unsigned long nb, char *base, unsigned long d, int fd)
{
	int	rt;

	rt = 0;
	if (nb >= d)
		rt += putnbrbase(nb / d, base, d, fd);
	rt += write(fd, &base[nb % d], 1);
	return (rt);
}

int	putnbr_base(long nbr, char *base, int fd)
{
	unsigned long	nb;
	unsigned long	d;
	int				rt;

	rt = 0;
	d = check_base(base);
	if (!d)
		return (0);
	else
	{
		if (nbr < 0)
		{
			rt += write(fd, "-", 1);
			nb = -nbr;
		}
		else
			nb = nbr;
		rt += putnbrbase(nb, base, d, fd);
	}
	return (rt);
}
