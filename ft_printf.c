/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/01/30 17:03:35 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_putputchar(char c)
{
	write(1, &c, 1);
}

void	ft_putputstr(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putputchar(s[i]);
		i++;
	}
}

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
            printf("%d", count);
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
	while (nb != 4)
	{
		char *n;

		n = va_arg(ap, char *);
		printf("%d", ft_countformat(n));
		printf("%s.\n", n);
		++nb;
	}
	va_end(ap);
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
int main(void)
{
	ft_printf("\n","efefe", "%%fff", "%%J'te", "cccc");
	return (0);
}
