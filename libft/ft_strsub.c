/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 22:22:16 by cparis            #+#    #+#             */
/*   Updated: 2016/11/25 22:14:38 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, unsigned long len)
{
	int		i;
	char	*strsub;

	if (s == 0)
		return (0);
	strsub = (char*)malloc(sizeof(char) * (len + 1));
	if (strsub == 0)
		return (0);
	i = 0;
	while (len--)
	{
		strsub[i] = s[start + i];
		i++;
	}
	strsub[i] = '\0';
	return (strsub);
}
