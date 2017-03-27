/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 14:18:24 by maleroy           #+#    #+#             */
/*   Updated: 2017/03/24 18:55:03 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*ft_reset_flag(void)
{
	t_flags	*newflag;

	if (!(newflag = malloc(sizeof(t_flags))))
		return (NULL);
	ft_bzero(newflag, sizeof(t_flags));
	return (newflag);
}

t_conversion	*ft_reset_conv(void)
{
	t_conversion	*newconv;

	if (!(newconv = malloc(sizeof(t_conversion))))
		return (NULL);
	ft_bzero(newconv, sizeof(t_conversion));
	newconv->flag = ft_reset_flag();
	newconv->modif = NONE;
	return (newconv);
}

char			*ft_free_join(char *s1, char *s2)
{
	char *tmp;

	if ((tmp = malloc(sizeof(char) * 1)))
		free(tmp);
	tmp = ft_strjoin(s1, s2);
	free(s2);
	s2 = tmp;
	return (s2);
}
