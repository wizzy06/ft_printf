/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:05:38 by cparis            #+#    #+#             */
/*   Updated: 2017/02/02 17:59:54 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

//gérer les flags #0-+ et espace

int     ft_first_flags()
{
    ft_min_width();
    ft_justify();
    ft_neg_or_pos();
    ft_blank_space();
    ft_sharp();
    ft_zero_filler();

}
    return(str);
}

void    ft_min_width()
{
   while (str[i] != '\0')
    {
        if (str[i] == '*')
        {

        }
}

void    ft_justify()
{
   while (str[i] != '\0')
    {
        if (str[i] == '-')
        {
                
        }
}

void    ft_neg_or_pos()
{
   while (str[i] != '\0')
    {
        if (str[i] == '+')
        {

        }
}

void    ft_blank_space()
{
        if (str[i] == ' ')
        {

        } 
}

void    ft_sharp()
{
        if (str[i] == '#')
        {

        }
}

void    ft_zero_filler()
{
        if (str[i] == '0')
        {

        }
}
