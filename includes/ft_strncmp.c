/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/13 16:13:59 by cparis            #+#    #+#             */
/*   Updated: 2016/11/26 17:36:07 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, unsigned long n)
{
	unsigned long	i;
	unsigned char	*c;
	unsigned char	*d;

	c = (unsigned char *)s1;
	d = (unsigned char *)s2;
	i = -1;
	while ((*c || *d) && ++i < n)
	{
		if (*c != *d)
			return (*c - *d);
		c++;
		d++;
	}
	return (0);
}
