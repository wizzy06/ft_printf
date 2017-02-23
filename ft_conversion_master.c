/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_master.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:08:53 by cparis            #+#    #+#             */
/*   Updated: 2017/02/23 19:45:51 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		ft_choose_camp(t_conversion *conv, const char *format, int choice)
{
	format = ft_conversion_type(*conv, *format);
	if (format == 's' || format == 'c')
	{
		format = ft_print_is_char();
		choice = 1;
	}
	else
	{
		format = ft_print_is_integer();
		choice = 2;
	}
	return (format);	
}

char		ft_