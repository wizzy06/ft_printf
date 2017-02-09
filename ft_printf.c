/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/02/09 04:08:14 by cparis           ###   ########.fr       */
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
            	if (*format == '%')
					ft_putchar('%');
           		 else if (*format == 'd' || *format == 'i')
            		ft_putnbr(va_arg(ap, int));
            	else if (*format == 'c' || *format == 'C')
                	ft_putchar(va_arg(ap, int));
            	else if (*format == 's' || *format == 'S')
               		ft_putstr(va_arg(ap, char *));
				else if (*format == 'x')
					ft_hexa_upper(va_arg(ap, int), 1); 
				else if (*format == 'X')
					ft_hexa_upper(va_arg(ap, int), 0);
				else if (*format == 'o')
					ft_int_to_octal(va_arg(ap, int));
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
	ft_printf("%c", 'X');
	ft_printf("\n");
	ft_printf( "%s", "coucou toi ca va ? \n");
	ft_printf( "%d\n", 12345);   
	ft_printf( "%x\n", 123465498);
	ft_printf( "%X\n", 123465498);
	ft_printf("%o", 68);
	return (0);
}





		/*	/////////////////MINIMUM WIDTH////////////////////
			int width_min;
			int len;
			
			width_min = ft_atoi(format);
			len = ft_strlen(n);
			if (width_min > len)
				{
					int i;
					int tmp;
					
					i = 0;
					tmp = width_min - len;
					while (++i != tmp)
						ft_putchar(' ');
					printf("%s\n", n);
					break;
				}
				else
				{
					printf("%s\n", n);
					break;
				}
				*/
			//////////////CONVERSION PROCEDURE/////////////////


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