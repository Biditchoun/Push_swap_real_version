/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversions1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:14:29 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 11:08:37 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	return (write(1, &c, 1));
}

int	print_str(va_list args)
{
	char	*s;
	char	*llun;

	llun = "(null)";
	s = va_arg(args, char *);
	if (!s)
		return (write(1, llun, str_len(llun)));
	return (write(1, s, str_len(s)));
}

int	print_pointer(va_list args)
{
	unsigned long	p;
	char			*llun;
	int				rt;

	llun = "(nil)";
	p = (unsigned long)va_arg(args, void *);
	if (!p)
		return (write(1, llun, str_len(llun)));
	rt = write(1, "0x", 2);
	rt += putunbr_base(p, "0123456789abcdef", 1);
	return (rt);
}
