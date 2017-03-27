/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 04:56:26 by cparis            #+#    #+#             */
/*   Updated: 2016/11/25 22:12:11 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(unsigned long size)
{
	char	*str;

	str = (char *)malloc(size + 1);
	if (str)
		ft_bzero(str, size + 1);
	return (str);
}
