/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:48:48 by cparis            #+#    #+#             */
/*   Updated: 2017/02/09 04:08:59 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "libft/libft.h"
#include "srcs/color_picker.c"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int		ft_printf(const char *format, ...);
int     ft_hexa_upper(long int	decimal_nbr, int up_low);
void	ft_hexa_lower(char c); 
int	    ft_int_to_octal(long nbr);


#endif
