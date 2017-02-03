/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 14:38:21 by cparis            #+#    #+#             */
/*   Updated: 2017/01/25 15:34:57 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinch(char const *s1, char c)
{
	char			*new_str;
	unsigned long	i;
	unsigned long	s1_len;

	if (!s1 || !c)
		return (0);
	s1_len = ft_strlen(s1);
	new_str = ft_strnew(s1_len + 1);
	if (!new_str)
		return (0);
	i = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	*(new_str + i) = c;
	return (new_str);
}
