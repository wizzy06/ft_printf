/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_master.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:08:53 by cparis            #+#    #+#             */
/*   Updated: 2017/03/18 15:07:28 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_type(t_conversion *conv, va_list ap)
{
	if (!conv->type)
		conv->type = 'a';
	ft_check_type(conv);
	if (ft_strchr("douxXp", conv->type))
		ft_print_is_number(conv, ap);
	if (ft_strchr("cs%", conv->type))
		ft_print_is_char(conv,ap);	
}

void		ft_print_is_char(t_conversion *conv, va_list ap)
{
	if (conv->modif == L)
	{
		if (conv->type == 'c')
			ft_print_wchar(conv, va_arg(ap, wint_t));
		else if (conv->type == 's')
			ft_print_wstr(conv, va_arg(ap, wchar_t*));
	}
	else
	{
		if (conv->type == 'c')
			ft_print_char(conv, va_arg(ap, int));
		else if (conv->type == 's')
			ft_print_str(conv, va_arg(ap, char*));
	}
	if (conv->type == '%')
		ft_print_char(conv, '%');
}

void	  ft_print_is_number(t_conversion *conv, va_list ap)
{
	intmax_t nbr;

	if (conv->type == 'd')
	{
		nbr = ft_get_number_signed(conv, ap);
		if (nbr < 0 && (nbr *= -1))
			conv->sign = '-';
		else if (conv->flag->plus)
			conv->sign = '+';
		else if (conv->flag->space)
			conv->sign = ' ';
	}
	else
		nbr = ft_get_number_unsigned(conv, ap);
	if (ft_strchr("du", conv->type))
		ft_print_du(conv, (uintmax_t)nbr);
	else if (conv->type == 'o')
		ft_print_o(conv, (uintmax_t)nbr);
	else if (ft_strchr("xp", conv->type))
		ft_print_xp(conv, (uintmax_t)nbr);
	else if (conv->type == 'X')
		ft_print_x_caps(conv, (uintmax_t)nbr);
}

void		ft_check_type(t_conversion *conv)
{
	if (ft_strchr("DOU", conv->type))
	{
		conv->modif = L;
		conv->type = ft_tolower(conv->type);
	}
	else if (conv->type == 'i')
		conv->type = 'd';
	else if (conv->type == 'p')
	{
		conv->modif = L;
		conv->flag->sharp = 1;
	}
	else if (ft_strchr("CS", conv->type))
	{
		conv->modif = L;
		conv->type = ft_tolower(conv->type);
	}
}