/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_master.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:08:53 by cparis            #+#    #+#             */
/*   Updated: 2017/02/11 14:47:16 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversion_master(va_list ap, const char format)
{
	if (format == '%')
		ft_putchar('%');
    else if (format == 'd' || format == 'i')
		ft_putnbr(va_arg(ap, int));
    else if (format == 'c' || format == 'C')
       	ft_putchar(va_arg(ap, int));
	else if (format == 's' || format == 'S')
    	ft_putstr(va_arg(ap, char *));
	else if (format == 'x')
		ft_hexa_upper(va_arg(ap, int), 1); 
	else if (format == 'X')
		ft_hexa_upper(va_arg(ap, int), 0);
	else if (format == 'o')
		ft_int_to_octal(va_arg(ap, int));
	else if (format == 'u')
        ft_putnbr(va_arg(ap, unsigned int));
	else if (format == 'p')
		ft_pointer_adress(va_arg(ap, void *));
}

