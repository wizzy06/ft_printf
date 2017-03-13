/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_master.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:08:53 by cparis            #+#    #+#             */
/*   Updated: 2017/03/13 15:13:51 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_choose_camp(t_conversion *conv, const char *format, int choice)
{
	format = ft_conversion_type(*conv, *format);
	if (!format)
		return (0);
	if (conv->type == 's' || conv->type == 'c')
		choice = 1;
	else 
		choice = 2;
	return (format);
}

char		ft_print_is_char(t_conversion *conv, const char *format, va_arg ap, int *choice)
{
	if (choice == 1)
	{
		
	}
}

char		ft_print_is_integer(t_conversion *conv, const char *format, int *choice)
{
	if (choice == 2)
	{

	}
}