/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_convert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 17:21:35 by cparis            #+#    #+#             */
/*   Updated: 2017/02/03 17:33:27 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void    format_character(char c, unsigned char uc)
{
    
}

void    format_integer(int d, int ud)
{

}

void    format_pointer(int *ptr)
{

}

void    format_octal(int octal)
{

}

void    format_hexadecimal(char upper, char lower)
{

}

void    format_string(char *str)
{

}


   
void    format(const char *format, ...)
{
	va_list ap;
	va_list ap2;

	char *string;
	va_start(ap, format);
	while (*format)
	{
		if(format == "%s")
		{
			s = va_arg(ap, char);
			ft_putstr(s);
			break;
		}
		if( format == '%d')
		{
			d = va_arg(ap, int);
			ft_putnbr(d);
			break;
		}
		if(format == '%c')
		{
			c = va_arg(ap, char);
			ft_putchar(c);
			break;
		}
	}
	va_end(ap);
}