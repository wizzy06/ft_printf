/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:43:07 by maleroy           #+#    #+#             */
/*   Updated: 2017/03/24 19:14:35 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_conv_ex(uintmax_t nb)
{
	if (nb >= 10)
		return (nb - 10 + 'a');
	else
		return (nb + '0');
}

char			*ft_itoa_base(uintmax_t value, uintmax_t base)
{
	int			i;
	char		*str;
	uintmax_t	tmp;

	i = 0;
	tmp = value;
	while (tmp >= base)
	{
		tmp = tmp / base;
		i++;
	}
	if (!(str = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i + 1] = '\0';
	while (i >= 0)
	{
		tmp = value % base;
		str[i] = ft_conv_ex(tmp);
		value /= base;
		i--;
	}
	return (str);
}
