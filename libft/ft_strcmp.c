/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 20:08:12 by cparis            #+#    #+#             */
/*   Updated: 2016/11/16 17:07:33 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int				i;
	unsigned char	*c;
	unsigned char	*d;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	c = (unsigned char *)s1;
	d = (unsigned char *)s2;
	return (c[i] - d[i]);
}
