/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/02/03 15:27:04 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

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

void	ft_printf(const char *format, ...)
{
	va_list ap;
	int nb;
	
	nb = 0;
	va_start(ap, format);
	while (nb != 1)
	{
		char *n;

		n = va_arg(ap, char *);

		while (*format)
		{
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
		}		
		++nb;
	}
	va_end(ap);
}

/*int	ft_width_master(int width_min, int len)
{
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
			return (-1);
	}
	else
		return (1);
}
*/
int main(void)
{
	ft_printf("4", "coucou");
	return (0);
}






/*

void	format(const char *format, ...)
{
	va_list ap;
	va_list ap2;
	char c;
	char *s;
	int d;

	va_start(ap, format);
	va_copy(ap2, ap);
	while (*format)
	{
		if(format == "s")
		{
			s = va_arg(ap, char *);
			printf("string %s\n", s);
			break;
		}
		if( format == 'd')
		{
			d = va_arg(ap, int);
			printf("int %d\n", d);
			break;
		}
		if(format == 'c')
		{
			c = va_arg(ap, int);
			printf("char %c\n", c);
			break;
		}
	}
	va_end(ap);
	va_end(ap2);
}
*/