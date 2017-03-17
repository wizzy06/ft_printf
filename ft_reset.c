/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 15:50:48 by cparis            #+#    #+#             */
/*   Updated: 2017/03/17 18:52:46 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	*reset_flag(void)
{
	t_flags	*new_flag;

	new_flag = malloc(sizeof(t_flags));
	ft_bzero(new_flag, sizeof(t_flags));
	return (new_flag);
}

t_conversion	*reset_conv(void)
{
	t_conversion	*new_conv;

	new_conv = malloc(sizeof(t_conversion));
	ft_bzero(new_conv, sizeof(t_conversion));
	new_conv->flag = reset_flag();
	new_conv->modif = NONE;
	return (new_conv);
}

char			*free_join(char *s1, char *s2)
{
	char *tmp;

	tmp = malloc(sizeof(char) * 1);
	free(tmp);
	tmp = ft_strjoin(s1, s2);
	free(s2);
	s2 = tmp;
	return (s2);
}