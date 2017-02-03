/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 22:30:42 by cparis            #+#    #+#             */
/*   Updated: 2016/11/26 17:33:42 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, unsigned long n)
{
	unsigned long len;

	if (*s2 == '\0')
		return ((char *)s1);
	len = ft_strlen(s2);
	while (*s1 != '\0' && n-- >= len)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, len) == 0)
			return ((char *)s1);
		s1++;
	}
	return (0);
}
