/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 18:28:37 by cparis            #+#    #+#             */
/*   Updated: 2016/11/26 17:17:13 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, unsigned long n)
{
	unsigned long	i;
	unsigned char	*dest_1;
	unsigned char	*src_1;
	unsigned char	j;

	dest_1 = (unsigned char*)dest;
	src_1 = (unsigned char*)src;
	j = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if ((*dest_1++ = *src_1++) == j)
			return (dest_1);
		i++;
	}
	return (0);
}
