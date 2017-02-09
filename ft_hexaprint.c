/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexaprint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 03:04:16 by cparis            #+#    #+#             */
/*   Updated: 2017/02/09 03:24:27 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexa_upper(long int	decimal_nbr, int up_low)
{
  int i;
  int j;
  int temp;
  char hexa_nbr[100];

  i = 0;
	while (decimal_nbr != 0)
	{
    temp = decimal_nbr % 16;
		if (temp < 10)
			temp = temp + 48;
    	else
			temp = temp + 55;
	hexa_nbr[i++] = temp;
	decimal_nbr = decimal_nbr / 16;
	}
	j = i;
	while (j-- > 0)
	{
		if (up_low == 0)
			ft_putchar(hexa_nbr[j]);
		else
			ft_hexa_lower(hexa_nbr[j]);
	}
	return (0);
}

void	ft_hexa_lower(char c)
{
	if (c == 'A')
		ft_putchar('a');
	if (c == 'B')
		ft_putchar('b');
	if (c == 'C')
		ft_putchar('c');
	if (c == 'D')
		ft_putchar('d');
	if (c == 'E')
		ft_putchar('e');
	if (c == 'F')
		ft_putchar('f');
	if (c >= '0' && c <= '9')
		ft_putchar(c);
}