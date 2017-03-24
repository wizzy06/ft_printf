/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_num.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 11:55:11 by maleroy           #+#    #+#             */
/*   Updated: 2017/03/24 18:49:43 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_get_num_signed(t_conversion *conv, va_list ap)
{
	if (conv->modif == HH)
		return ((char)va_arg(ap, int));
	if (conv->modif == H)
		return ((short)va_arg(ap, int));
	if (conv->modif == L)
		return (va_arg(ap, long));
	if (conv->modif == LL)
		return (va_arg(ap, long long));
	if (conv->modif == J)
		return (va_arg(ap, intmax_t));
	if (conv->modif == Z)
		return (va_arg(ap, ssize_t));
	return (va_arg(ap, int));
}

uintmax_t	ft_get_num_unsigned(t_conversion *conv, va_list ap)
{
	if (conv->modif == HH)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (conv->modif == H)
		return ((unsigned short)va_arg(ap, unsigned int));
	if (conv->modif == L)
		return (va_arg(ap, unsigned long));
	if (conv->modif == LL)
		return (va_arg(ap, unsigned long long));
	if (conv->modif == J)
		return (va_arg(ap, uintmax_t));
	if (conv->modif == Z)
		return (va_arg(ap, size_t));
	return (va_arg(ap, unsigned int));
}
