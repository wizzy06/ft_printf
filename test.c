/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 16:10:07 by cparis            #+#    #+#             */
/*   Updated: 2017/01/30 16:27:32 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft/libft.h"

int		main(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
    str = "%%";
    while (str[i] != '\0')
	{
		if(str[i] == '%')
			count++;
            printf("\n%d", count);
            if(str[i] == '%' && count == 10)
            break;
		i++;
	}
	return (count);
}