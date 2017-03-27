/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 12:20:54 by maleroy           #+#    #+#             */
/*   Updated: 2017/03/24 18:52:50 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_du(t_conversion *conv, uintmax_t num)
{
	char	*str;
	int		len;

	str = ft_itoa_base(num, 10);
	len = ft_strlen(str);
	if (str[0] == '0' && conv->prec_set && conv->precision == 0)
		str[0] = '\0';
	while (conv->precision > len)
	{
		str = ft_free_join("0", str);
		len++;
	}
	while (conv->flag->zero && conv->min_width > len
			&& !conv->prec_set && !conv->flag->minus)
	{
		if (conv->sign && conv->min_width == len + 1)
			break ;
		str = ft_free_join("0", str);
		len++;
	}
	if (conv->sign)
		str = ft_free_join(&conv->sign, str);
	ft_print_num_spaced(conv, str);
	free(str);
}

void		ft_print_o(t_conversion *conv, uintmax_t num)
{
	char	*str;
	int		len;

	str = ft_itoa_base(num, 8);
	len = ft_strlen(str);
	if (str[0] == '0' && conv->prec_set && conv->precision == 0)
		str[0] = '\0';
	if (conv->flag->pound && str[0] != '0')
	{
		str = ft_free_join("0", str);
		len++;
	}
	while (conv->precision > len)
	{
		str = ft_free_join("0", str);
		len++;
	}
	while (conv->flag->zero && conv->min_width > len
			&& !conv->prec_set && !conv->flag->minus)
	{
		str = ft_free_join("0", str);
		len++;
	}
	ft_print_num_spaced(conv, str);
	free(str);
}

void		ft_print_xp(t_conversion *conv, uintmax_t num)
{
	char	*str;
	int		len;

	str = ft_itoa_base(num, 16);
	len = ft_strlen(str);
	if (str[0] == '0' && conv->prec_set && conv->precision == 0)
		str[0] = '\0';
	while (conv->precision > len)
	{
		str = ft_free_join("0", str);
		len++;
	}
	while (conv->flag->zero && conv->min_width > len
			&& !conv->prec_set && !conv->flag->minus)
	{
		if (((conv->flag->pound && num > 0) || conv->type == 'p')
				&& conv->min_width == len + 2)
			break ;
		str = ft_free_join("0", str);
		len++;
	}
	if ((conv->flag->pound && num > 0) || conv->type == 'p')
		str = ft_free_join("0x", str);
	ft_print_num_spaced(conv, str);
	free(str);
}

void		ft_print_x_caps(t_conversion *conv, uintmax_t num)
{
	char	*str;
	int		len;

	str = ft_itoa_base(num, 16);
	len = ft_strlen(str);
	if (str[0] == '0' && conv->prec_set && conv->precision == 0)
		str[0] = '\0';
	str = ft_strupcase(str);
	while (conv->precision > len)
	{
		str = ft_free_join("0", str);
		len++;
	}
	while (conv->flag->zero && conv->min_width > len
			&& !conv->prec_set && !conv->flag->minus)
	{
		if (conv->flag->pound && num > 0 && conv->min_width == len + 2)
			break ;
		str = ft_free_join("0", str);
		len++;
	}
	if (conv->flag->pound && num > 0)
		str = ft_free_join("0X", str);
	ft_print_num_spaced(conv, str);
	free(str);
}