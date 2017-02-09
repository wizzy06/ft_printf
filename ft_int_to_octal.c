/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_octal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 04:09:39 by cparis            #+#    #+#             */
/*   Updated: 2017/02/09 04:10:05 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_int_to_octal(long nbr)
{
    int octal[100];
	int j;
	int i;

	i = 0;
    while (nbr != 0)
    {
        octal[i++] = nbr % 8;
        nbr = nbr / 8;
    }
	j = i;
	while (j-- > 0)
		ft_putnbr(octal[j]);
    return (0);
}