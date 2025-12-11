/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:42:24 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 11:04:25 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**function_pointers_tab(void)
{
	void	**rt;

	rt = (void **)malloc(sizeof(void *) * 10);
	if (!rt)
		return (NULL);
	rt[0] = &print_char;
	rt[1] = &print_str;
	rt[2] = &print_pointer;
	rt[3] = &print_int;
	rt[4] = &print_int;
	rt[5] = &print_unint;
	rt[6] = &print_hex;
	rt[7] = &print_caphex;
	rt[8] = &print_percent;
	rt[9] = NULL;
	return (rt);
}

int	write_arg(const char *s, va_list args, char *type, void **f_type)
{
	int	i;
	int	(*f)(va_list);

	i = 0;
	while (type[i] && *s != type[i])
		i++;
	if (type[i])
	{
		f = f_type[i];
		return (f(args));
	}
	return (0);
}

int	ft_printf(const char *s, ...)
{
	int		rt;
	int		i;
	void	**f_type;
	char	*type;
	va_list	args;

	if (!s)
		return (-1);
	type = "cspdiuxX%";
	f_type = function_pointers_tab();
	if (!f_type)
		return (-1);
	va_start(args, s);
	rt = 0;
	i = -1;
	while (s[++i])
	{
		if (s[i] != '%')
			rt += write(1, &s[i], 1);
		else
			rt += write_arg(&s[++i], args, type, f_type);
	}
	va_end(args);
	free(f_type);
	return (rt);
}
