/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:02:18 by cparis            #+#    #+#             */
/*   Updated: 2017/03/17 19:18:14 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void        ft_print_du(t_conversion *conv, uintmax_t nbr)
{
    char    *str;
    int     len;

    str = ft_itoa_base(nbr, 10);
    len = ft_strlen(str);
    if (str[0] == '0' && conv->precision)
        str[0] = '\0';
    while (conv->precision > len)
    {
        str = free_join("0", str);
        len++;
    }
    while (conv->flag->zero && conv->min_width > len &&
    !conv->flag->minus)
    {
        if (conv->sign && conv->min_width == len + 1)
            break;
        str = free_join("0", str);
        len++;
    }
    if (conv->sign)
        str = free_join(&conv->sign, str);
    ft_print_number_with_space(conv, str);
    free(str);
}

void        ft_print_o(t_conversion *conv, uintmax_t nbr)
{
    char	*str;
	int		len;

	str = ft_itoa_base(nbr, 8);
	len = ft_strlen(str);
	if (str[0] == '0' && conv->precision == 0)
		str[0] = '\0';
	if (conv->flag->sharp && str[0] != '0')
	{
		str = free_join("0", str);
		len++;
	}
	while (conv->precision > len)
	{
		str = free_join("0", str);
		len++;
	}
	while (conv->flag->zero && conv->min_width > len
			&& !conv->flag->minus)
	{
		str = free_join("0", str);
		len++;
	}
	ft_print_number_with_space(conv, str);
	free(str);
}

void		ft_print_xp(t_conversion *conv, uintmax_t nbr)
{
	char	*str;
	int		len;

	str = ft_itoa_base(nbr, 16);
	len = ft_strlen(str);
	if (str[0] == '0' && conv->precision == 0)
		str[0] = '\0';
	while (conv->precision > len)
	{
		str = free_join("0", str);
		len++;
	}
	while (conv->flag->zero && conv->min_width > len
			&& !conv->flag->minus)
	{
		if (((conv->flag->sharp && nbr > 0) || conv->type == 'p')
				&& conv->min_width == len + 2)
			break ;
		str = free_join("0", str);
		len++;
	}
	if ((conv->flag->sharp && num > 0) || conv->type == 'p')
		str = free_join("0x", str);
	ft_print_number_with_space(conv, str);
	free(str);
}

void		ft_print_x_caps(t_conversion *conv, uintmax_t nbr)
{
	char	*str;
	int		len;

	str = ft_itoa_base(nbr, 16);
	len = ft_strlen(str);
	if (str[0] == '0' && conv->precision == 0)
		str[0] = '\0';
	str = ft_strupcase(str); // ??????
	while (conv->precision > len)
	{
		str = free_join("0", str);
		len++;
	}
	while (conv->flag->zero && conv->min_width > len
			&& !conv->flag->minus)
	{
		if (conv->flag->sharp && nbr > 0 && conv->min_width == len + 2)
			break ;
		str = free_join("0", str);
		len++;
	}
	if (conv->flag->sharp && nbr > 0)
		str = free_join("0X", str);
	ft_print_number_with_space(conv, str);
	free(str);
}