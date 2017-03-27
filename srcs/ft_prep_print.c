/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:14:01 by maleroy           #+#    #+#             */
/*   Updated: 2017/03/24 18:50:40 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const char	*ft_lf_flag(const char *format, t_conversion *conv)
{
	while (*format && ft_strchr("#0-+ ", *format))
	{
		if (*format == '#')
			conv->flag->pound = 1;
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

static const char	*ft_lf_min_width(const char *format, t_conversion *conv)
{
	if (*format && !conv->min_width)
	{
		conv->min_width = ft_atoi(format);
		while (ft_isdigit(*format))
			format++;
	}
	return (format);
}

static const char	*ft_lf_prec(const char *format, t_conversion *conv)
{
	if (*format != '.')
		return (format);
	format++;
	conv->precision = ft_atoi(format);
	conv->prec_set = 1;
	while (ft_isdigit(*format))
		format++;
	return (format);
}

static const char	*ft_lf_modif(const char *format, t_conversion *conv)
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

const char			*ft_prep_print(const char *format, va_list ap)
{
	t_conversion	*conv;
	size_t			stop;

	conv = ft_reset_conv();
	while (*format && !conv->type)
	{
		stop = ft_strlen(format);
		format = ft_lf_flag(format, conv);
		format = ft_lf_min_width(format, conv);
		format = ft_lf_prec(format, conv);
		format = ft_lf_modif(format, conv);
		if (*format && ft_strchr("dDioOuUxXpcCsS%", *format))
		{
			conv->type = *format;
			format++;
		}
		if (stop == ft_strlen(format))
			break ;
	}
	ft_print_type(conv, ap);
	if (conv->flag)
		free(conv->flag);
	if (conv)
		free(conv);
	return (format);
}
