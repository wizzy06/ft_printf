/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_with_space.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 18:18:29 by cparis            #+#    #+#             */
/*   Updated: 2017/03/17 18:20:48 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		    ft_print_space(int len, int min, char c)
{
	while (min > len)
	{
		min--;
		ft_true_print(&c, 1);
	}
}

static void	    ft_print_left(t_conversion *conv, char *str)
{
	ft_true_print(str, ft_strlen(str));
	ft_print_space(ft_strlen(str), conv->min_width, ' ');
}

void		    ft_print_number_with_space(t_conversion *conv, char *str)
{
	if (conv->flag->minus)
		return (ft_print_left(conv, str));
	ft_print_space(ft_strlen(str), conv->min_width, ' ');
	ft_true_print(str, ft_strlen(str));
}

void		    ft_true_print(void *mem, int size)
{
	char	*str;
	int		ret;
	int		i;

	str = mem;
	i = 0;
	while (i < size)
	{
		ret = write(1, str + i, 1);
		if (ret == -1)
			ft_count_octet(0, -1);
		else
			ft_count_octet(1, 1);
		i++;
	}
}