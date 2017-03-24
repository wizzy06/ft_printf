/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 13:56:06 by maleroy           #+#    #+#             */
/*   Updated: 2017/03/24 19:15:26 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_count_octet(int option, int add)
{
	static int octet = 0;

	if (add == -1)
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

static int	ft_print_start(const char *format, va_list ap)
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
			if (*format == '\0')
				break ;
			else
				format = ft_prep_print(format, ap);
		}
	}
	return (ft_count_octet(0, 0));
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		ret;

	if (!format)
		return (0);
	va_start(ap, format);
	ret = ft_print_start(format, ap);
	va_end(ap);
	return (ret);
}