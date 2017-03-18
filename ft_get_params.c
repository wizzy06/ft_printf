/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:02:19 by cparis            #+#    #+#             */
/*   Updated: 2017/03/18 15:03:09 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char    *set_flag(t_conversion *conv, const char *format)
{
	while (*format && ft_strchr("#0-+ ", *format))
	{
		if (*format == '#')
			conv->flag->sharp = 1;
		else if (*format == '0')
			conv->flag->zero = 1;
		else if (*format == '-')
			conv->flag->minus = 1;
		else if (*format == '+')
			conv->flag->plus = 1;
		else if (*format == ' ')
			conv->flag->space = 1;
		else if (*format == '\0')
			break ;
		format++;
	}
	return (format);
}

static const char    *ft_minimum_width(t_conversion *conv, const char *format)
{
	if (*format && !conv->min_width)
	{
		conv->min_width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}

static const char    *ft_precision(t_conversion *conv, const char *format)
{
	if (*format != '.')
		return (format);
	format++;
	conv->precision = ft_atoi(format);
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static const char    *ft_modif_letters(t_conversion *conv, const char *format)
{
	if (*format && !ft_strchr("hljz", *format))
		return (format);
	if (ft_strncmp(format, "hh", 2) == 0)
	{
		conv->modif = HH;
		return (format + 2);
	}
	if (ft_strncmp(format, "ll", 2) == 0)
	{
		conv->modif = LL;
		return (format + 2);
	}
	else if (*format == 'h')
		conv->modif = H;
	else if (*format == 'l')
		conv->modif = L;
	else if (*format == 'j')
		conv->modif = J;
	else if (*format == 'z')
		conv->modif = Z;
	return (format + 1);
}

const char    *ft_init_param(const char *format, va_list ap)
{
    t_conversion    *conv;
    unsigned long   stop;

    conv = reset_conv();
    while (*format && !conv->type)
    {
        stop = ft_strlen(format);
        format = set_flag(conv, format);
        format = ft_minimum_width(conv, format);
        format = ft_precision(conv, format);
        format = ft_modif_letters(conv, format);
        if (*format && ft_strchr("dDioOuUxXpcCsS%", *format))
        {
            conv->type = *format;
            format++;
        }
        if (stop == ft_strlen(format))
            break;
    }
    ft_print_type(conv, ap);
    if (conv->flag)
        free(conv->flag);
        if (conv)
            free(conv);
    return (format);
}