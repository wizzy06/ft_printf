/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/01/29 03:54:54 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

int		ft_countformat(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
		j++;
	i++;
	return (j);
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
		printf(ft_countformat(n));
		printf("%s.\n", n);
		++nb;
	}
	va_end(ap);
}

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

int main(void)
{
	ft_printf("\n","Hello", "Bea", "J'te", "Baise");
	return (0);
}
