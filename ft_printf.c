/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:52:27 by cparis            #+#    #+#             */
/*   Updated: 2017/03/17 19:03:44 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

int				ft_count_octet(int option, int add)
{
	static int	octet = 0;

	if (add = -1)
		octet = -1;
	if (octet != -1)
	{
		if (option == 1)
			octet = octet + add;
		if (option == 0)
		{
			add = octet;
			octet = 0;
			return (add);
		}
	}
	return (octet);
}

int				ft_printf(const char *format, ...)
{
	va_list ap;
	int 	ret;
	
	if (!format)
		return (0);
	va_start(ap, format);
	ret = ft_start_print(format, ap);
	va_end(ap);
	return (ret);
}

int		ft_start_print(const char *format, va_list ap)
{
	int i;

	while (*format)
	{
		if (*format != '%')
		{
			i = write(1, format, 1);
			ft_count_octet(1, i);
			format++;
		}
		else
		{
			format++;
			if (*format != '\0')
				break;
			else
				format = ft_init_params(format, ap);
		}
	}
	return (ft_count_octet(0, 0));
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