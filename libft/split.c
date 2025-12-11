/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:11:21 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 10:21:29 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	store_strings(char *s, char **rt, char c)
{
	int	i;
	int	nb_s;

	nb_s = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
		{
			s[i] = 0;
			i++;
		}
		if (s[i])
			rt[nb_s++] = &s[i];
		while (s[i] && s[i] != c)
			i++;
	}
}

char	**split(char *s, char c)
{
	char	**rt;
	int		i;
	int		nb_s;

	if (!s)
		return (NULL);
	nb_s = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			nb_s++;
		while (s[i] && s[i] != c)
			i++;
	}
	rt = malloc(sizeof(char *) * (nb_s + 1));
	if (!rt)
		return (NULL);
	store_strings(s, rt, c);
	return (rt);
}
