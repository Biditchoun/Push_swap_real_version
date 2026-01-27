/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_cpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sawijnbe <sawijnbe@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 07:18:19 by sawijnbe          #+#    #+#             */
/*   Updated: 2026/01/27 07:23:42 by sawijnbe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	arr_cpy(int *dest, int *src, int src_size, int end)
{
	int	i;

	i = -1;
	while (++i < src_size && src[i] != end)
		dest[i] = src[i];
	if (i < src_size)
		dest[i] = src[i];
	return (i);
}
