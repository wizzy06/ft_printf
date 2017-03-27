/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 15:05:28 by maleroy           #+#    #+#             */
/*   Updated: 2017/03/24 18:53:57 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_chars(t_conversion *conv, char *str, int size)
{
	if (conv->prec_set && conv->type == 's')
		size = (size < conv->precision ? size : conv->precision);
	if (conv->flag->minus)
	{
		ft_true_print(str, size);
		ft_print_spacing(size, conv->min_width, ' ');
		return ;
	}
	if (conv->flag->zero)
		ft_print_spacing(size, conv->min_width, '0');
	else
		ft_print_spacing(size, conv->min_width, ' ');
	ft_true_print(str, size);
}

void			ft_print_char(t_conversion *conv, char c)
{
	ft_print_chars(conv, &c, 1);
}

void			ft_print_string(t_conversion *conv, char *str)
{
	if (!str)
		str = "(null)";
	ft_print_chars(conv, str, ft_strlen(str));
}
