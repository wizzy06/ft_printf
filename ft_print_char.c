/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:25:13 by cparis            #+#    #+#             */
/*   Updated: 2017/03/17 18:28:42 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ft_print_chars(t_conversion *conv, char *str, int size)
{
	if (conv->type == 's')
		size = (size < conv->precision ? size : conv->precision);
	if (conv->flag->minus)
	{
		ft_true_print(str, size);
		ft_print_space(size, conv->min_width, ' ');
		return ;
	}
	if (conv->flag->zero)
		ft_print_space(size, conv->min_width, '0');
	else
		ft_print_space(size, conv->min_width, ' ');
	ft_true_print(str, size);
}

void			ft_print_char(t_conversion *conv, char c)
{
	ft_print_chars(conv, &c, 1);
}

void			ft_print_str(t_conversion *conv, char *str)
{
	if (!str)
		str = "(null)";
	ft_print_chars(conv, str, ft_strlen(str));
}