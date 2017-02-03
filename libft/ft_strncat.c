/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:55:48 by cparis            #+#    #+#             */
/*   Updated: 2016/11/26 17:19:43 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, unsigned long n)
{
	unsigned long i;
	unsigned long lenght;

	i = 0;
	lenght = ft_strlen(dest);
	while (src[i] != '\0' && i < n)
	{
		dest[lenght + i] = src[i];
		i++;
	}
	dest[lenght + i] = '\0';
	return (dest);
}
