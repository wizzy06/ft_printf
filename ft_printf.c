/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/02/09 06:10:04 by cparis           ###   ########.fr       */
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
				else if (*format == 'u')
            		ft_putnbr(va_arg(ap, unsigned int));
				else if (*format == 'p')
					pointer_function(va_arg(ap, void *));
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
	char *str = "coucou";
	ft_printf("Il est temps de tester le %d et le %s", test_octal, str);
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

void	pointer_function(void *ptr)
{
        unsigned char t[sizeof ptr];
        size_t i;

        ft_memcpy(t, &ptr, sizeof ptr);
		i = 0;
		while (++i < sizeof ptr)
		{
			ft_hexa_upper(t[i], 1);			
		}

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
