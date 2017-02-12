/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/02/12 18:00:27 by cparis           ###   ########.fr       */
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
				ft_minimum_width(ap, format);
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
	ft_printf( "%25X\n", 1238);
	return (0);
}

/*void	ft_minimum_width(va_list ap, const char *format)
{
	char *str;
	int i;
	
	i = -1;
	str = (char *) format;
	while (str[i++] != '\0' && ft_isdigit(str[i]))
	{
		int tmp;
		int len;
		len = ft_strlen(ap);
		tmp = ft_atoi(&str[i++]);
		printf("There is/are %d.\n", tmp);
		if (len >= tmp)
		{
			printf("marche fdp");
		}
	}
}
*/
