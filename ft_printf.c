/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/02/11 16:26:13 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_countformat(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
    while (str[i] != '\0')
	{
		if(str[i] == '%')
			count++;
            if(str[i] == '%' && count == 10)
            break;
		i++;
	}
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int size;
	
	va_start(ap, format);
	size = 0;
	while (*format != '\0')
		{
			if (*format == '%')
			{
				format++;
				ft_conversion_master(ap, *format);
			}
			else
        	{
            	ft_putchar(*format);
            	size++;
        	}
			format++;
		}
	va_end(ap);
	return (size);
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
	ft_printf( "%s", "coucou toi ca va ? \n");
	ft_printf( "%d\n", 12345);
	ft_printf( "%u\n", 12345);   
	ft_printf( "%x\n", 123465498);
	ft_printf( "%X\n", 123465498);
	ft_printf("%o\n", 68);
	ft_printf("%p\n", p);
	return (0);
}       