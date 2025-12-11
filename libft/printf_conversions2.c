/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_conversions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 15:49:59 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 11:09:19 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_int(va_list args)
{
	return (putnbr_base((long)va_arg(args, int), "0123456789", 1));
}

int	print_unint(va_list args)
{
	return (putnbr_base((long)va_arg(args, unsigned int), "0123456789", 1));
}

int	print_hex(va_list args)
{
	return (putnbr_base((long)va_arg(args, unsigned int),
			"0123456789abcdef", 1));
}

int	print_caphex(va_list args)
{
	return (putnbr_base((long)va_arg(args, unsigned int),
			"0123456789ABCDEF", 1));
}

int	print_percent(va_list args)
{
	(void)args;
	return (write(1, "%", 1));
}
