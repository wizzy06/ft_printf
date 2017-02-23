/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/02/23 18:07:01 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int size;
	t_conversion *conv;
	
	conv = reset_conv();
	va_start(ap, format);
	while (*format != '\0')
		{
			if (*format == '%')
			{
				format++;
				ft_get_params(*conv, *format);
			}
			else
        	{
            	ft_putchar(*format);
        	}
			
			format++;
		}
	va_end(ap);
}

int main(void)
{
	int test_octal = 3564542;
	int *p;
	p = &test_octal;
	char *str = "coucou 12";
	ft_printf("Il est temps de tester le %d et le %s\n", test_octal, str);
	ft_printf("%c", 'X');
	ft_printf("\n");
	ft_printf("%c", 'C');
	ft_printf("\n");
	ft_printf( "%s", "coucou \n");
	ft_printf( "%d\n", 12345);
	ft_printf( "%u\n", 12345);   
	ft_printf( "%x\n", 123465498);
	ft_printf( "%X\n", 123465498);
	ft_printf("%o\n", 68);
	ft_printf("%p\n", p);
	ft_printf( "%X\n", 1238);
	ft_printf("%12s", "c'est OK");
	return (0);
}