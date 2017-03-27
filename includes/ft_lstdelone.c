/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 23:03:55 by cparis            #+#    #+#             */
/*   Updated: 2017/01/20 16:45:33 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, unsigned long))
{
	t_list	*liste;
	t_list	*tmp;

	liste = *alst;
	if (liste)
	{
		tmp = liste->next;
		del(liste, liste->content_size);
		liste = tmp;
	}
	*alst = 0;
}
