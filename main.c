/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 01:52:10 by cparis            #+#    #+#             */
/*   Updated: 2017/01/30 17:35:00 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		main(void)
{
	//Affiche un nombre en décimale (un argument)
	printf("%f\n",10.1);
	//Affiche un nombre entier (Un argument)
	printf("%d\n", 12);
	//Affiche la string (prend un argument !)
	printf("%s\n", "coucou toi, j'ai 10 ans.");
	//Affiche tout en BRUT
	printf("Tu es très sexy aujourd'hui. :3 *-* \n");
	//Affiche le signe % seulement. (Un argument))
	printf("%%\n");
	//UN ARGUMENT !! 
	printf("coucou", "toi", "ca", "va","?");
	return (0);
}
