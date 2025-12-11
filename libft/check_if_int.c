/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:43:57 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 19:36:03 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_if_int(char *s)
{
	int		i;
	int		j;

	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	j = 0;
	while (s[i + j] && str_chr("0123456789", s[i + j]) > -1)
		if (j++ > 10)
			return (-1);
	if (a_toi(s) != a_tol(s))
		return (-1);
	return (0);
}
