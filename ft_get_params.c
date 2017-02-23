/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 18:02:19 by cparis            #+#    #+#             */
/*   Updated: 2017/02/23 18:24:28 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

static char    *set_flag(t_conversion *conv, const char *format)
{
    while (ft_strchr(" +#0-", *format))
    {
        if (format == "+")
            conv->flag->plus = 1;
        else if (format == "-")
            conv->flag->minus = 1;
        else if (format == "#")
            conv->flag->sharp = 1;
        else if (format == "0")
            conv->flag->zero = 1;
        else
            conv->flag->space = 1;
        format++;
    }
    return (format);
}

static char    *ft_minimum_width(t_conversion *conv, const char *format)
{
    conv->min_width = ft_atoi(format);
    while (ft_isdigit(format))
        format++;
    return (format);
}

static char    *ft_precision(t_conversion *conv, const char *format)
{
    if (ft_strchr(".", *format))
    {
        format++;
        conv->precision = ft_atoi(format);
        while (ft_isdigit(format))
            format++;
    }
    return (format);
}

static char    *ft_modif_letters(t_conversion *conv, const char *format)
{
    if (ft_strchr("hljz", *format))
    {
        if (ft_strncmp("hh", format, 2) == 0)
        {
            conv->modif = HH;
            return (format + 2);
        }
        else if (ft_strncmp("h", format, 1) == 0)
            conv->modif = H;
        else if (ft_strncmp("l", format, 1) == 0)
            conv->modif = L;
        else if (ft_strncmp("ll", format, 2) == 0)
        {
            conv->modif = LL;
            return (format + 2);
        }
        else if (ft_strncmp("j", format, 1) == 0)
            conv->modif = J;
        else
            conv->modif == Z;
        format++;
    }
    return (format);
}

/* char    *ft_pos_or_neg(t_conversion *conv, const char *format)
{

} 
*/

static char    *ft_conversion_type(t_conversion *conv, const char *format)
{
    if (format == ft_strchr("%dcsxXoup", *format))
    {
        if (format == '%')
            conv->type = '%';
        else if (format == 'd')
            conv->type = 'd';
        else if (format == 'c')
            conv->type = 'c';
        else if (format == 's')
            conv->type = 's';
        else if (format == 'x')
            conv->type = 'x';
        else if (format == 'X')
            conv->type = 'X';
        else if (format == 'o')
            conv->type = 'o';
        else if (format == 'u')
            conv->type = 'u';
        else
            conv->type = 'p';
        format++;   
    }
    return (format);
}

char    *ft_init_param(t_conversion *conv, const char *format)
{
    if (*format)
    {
        format = set_flag(*conv, *format);
        format = ft_minimum_width(*conv, *format);
        format = ft_precision(*conv, *format);
        format = ft_modif_letters(*conv, *format);
        format = ft_conversion_type(*conv, *format);
    }
    return (format);
}