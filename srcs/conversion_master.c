/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_master.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:08:53 by cparis            #+#    #+#             */
/*   Updated: 2017/02/02 16:41:30 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <unistd.h>

/* void     ft_string_convert(char *str)
{
    int i;

    ft_putstr(str[i]);
} */

void    ft_coucou(char c)
{
    write (1, &c, 1);

}

void	*ft_memcopy(void *dest, const void *src, unsigned long n)
{
	unsigned char	*s1;
	unsigned char	*s2;
	unsigned long	i;

	s1 = (unsigned char*)dest;
	s2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (s1);
}

void	ft_putnbrr(int n)
{
	if (n == -2147483648)
	{
		n = 147483648;
		ft_coucou('-');
		ft_coucou('2');
	}
	if (n < 0)
	{
		ft_coucou('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbrr(n / 10);
		ft_putnbrr(n % 10);
	}
	else
		ft_coucou(n + '0');
}

void     ft_coucoucou(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        ft_coucou(str[i]);
        i++;
    }

}
int  main(void)
{
    int i;
    char *str;

    10 = A;
    11 = B;
    12 = C;
    13 = D;
    14 = E;
    15 = F;

    
    if ()
}