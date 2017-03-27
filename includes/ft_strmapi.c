/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 23:52:53 by cparis            #+#    #+#             */
/*   Updated: 2016/11/20 00:02:02 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*strmapi;

	if (s == 0 || f == 0)
		return (0);
	strmapi = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (strmapi == 0)
		return (0);
	i = -1;
	while (s[++i])
		strmapi[i] = f(i, s[i]);
	strmapi[i] = '\0';
	return (strmapi);
}
