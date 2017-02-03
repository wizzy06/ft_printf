/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 21:44:45 by cparis            #+#    #+#             */
/*   Updated: 2016/11/26 17:18:47 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, unsigned long n)
{
	unsigned long	i;
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *)s1;
	src = (unsigned char *)s2;
	i = 0;
	if (src < dest)
	{
		while (++i <= n)
			dest[n - i] = src[n - i];
	}
	else
	{
		while (i < n)
		{
			dest[i] = src[i];
			i++;
		}
	}
	return (s1);
}
