/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer_adress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 14:28:50 by cparis            #+#    #+#             */
/*   Updated: 2017/02/11 15:01:08 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_pointer_adress(void *ptr)
{
        unsigned char t[sizeof ptr];
        size_t i;

        ft_memcpy(t, &ptr, sizeof ptr);
		i = 0;
       // write(1, "0x", 2);
		while (++i < sizeof ptr)
        {
			ft_hexa_upper(t[i], 1);
        }
}