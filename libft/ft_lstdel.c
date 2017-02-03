/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:04:59 by cparis            #+#    #+#             */
/*   Updated: 2017/01/20 16:45:56 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, unsigned long))
{
	t_list	*tmp;
	t_list	*liste;

	liste = *alst;
	while (liste != 0)
	{
		tmp = liste->next;
		del(liste, liste->content_size);
		liste = tmp;
	}
	*alst = 0;
}
