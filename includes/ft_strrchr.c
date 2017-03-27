/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 05:35:43 by cparis            #+#    #+#             */
/*   Updated: 2016/11/17 05:42:07 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	int		i;

	i = 0;
	str = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			str = (char*)s + i;
		i++;
	}
	if (c == 0)
		return ((char*)s + i);
	return (str);
}
