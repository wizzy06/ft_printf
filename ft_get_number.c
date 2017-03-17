/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 17:54:49 by cparis            #+#    #+#             */
/*   Updated: 2017/03/17 18:00:13 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t        ft_get_number_signed(t_conversion *conv, va_list ap)
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

uintmax_t        ft_get_number_unsigned(t_conversion *conv, va_list ap)
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