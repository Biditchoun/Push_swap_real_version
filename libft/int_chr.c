/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 17:20:30 by sawijnbe          #+#    #+#             */
/*   Updated: 2025/12/02 19:12:07 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	int_chr(const int *arr, int n, int arrsize)
{
	int	i;

	if (!arr)
		return (-1);
	i = -1;
	while (++i < arrsize)
		if (arr[i] == n)
			return (i);
	return (-1);
}
