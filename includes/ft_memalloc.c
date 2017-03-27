/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 01:41:17 by cparis            #+#    #+#             */
/*   Updated: 2016/11/26 18:19:58 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(unsigned long size)
{
	void	*pointeur;

	if (!size)
		return (0);
	pointeur = malloc(size);
	if (pointeur)
		ft_bzero(pointeur, size);
	return (pointeur);
}
