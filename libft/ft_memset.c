/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:35:40 by cparis            #+#    #+#             */
/*   Updated: 2016/11/26 17:15:04 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memset(void *b, int c, unsigned long len)
{
	unsigned char	*a;

	if (len == 0)
		return (b);
	a = (unsigned char *)b;
	while (len--)
	{
		*a = (unsigned char)c;
		if (len)
			a++;
	}
	return (b);
}
