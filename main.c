/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/29 01:52:10 by cparis            #+#    #+#             */
/*   Updated: 2017/03/13 16:52:50 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int		main(void)
{	
/*  sS p dD i o O uU xX cC à GERER

 	%s 	string of characters
	%p 	pointer
	%d or %i 	decimal integer
	%o 	octal integer
	%u 	unsigned decimal integer
	%x 	hexadecimal integer, using lower case
	%X 	hexadecimal integer, using upper case
	%c 	character
	%% 	Prints a % sign
*/

int number = 17;
char *str = "Petite string sympathique.";
int *ptr = &number;
int c;
unsigned int hexa = 259375111;
int max= 32767;
int min = -32767;
int max_false = 655465;
unsigned int min_unsigned = 0;
unsigned int max_unsigned = 65535;
int octal = 123;

//%s 	string of characters
	//printf("%S\n", str);
	printf(COLOR_RED "String of caracters (s)\n" COLOR_RESET);
	printf("%s\n\n", str);


//%p 	pointer adress of "number"
	printf(COLOR_GREEN "POINTER ADRESS (p)\n" COLOR_RESET);
	printf("%p\n\n", ptr);
	//printf("%P\n\n", ptr);

//%d or %i 	decimal integer (%D à inclure)
	printf(COLOR_RED "DECIMAL INTEGER (d i)\n" COLOR_RESET);
	printf("%d\n", min);
	printf("%i\n", max);
	printf("%d\n\n", max_false);
	printf("Il est temps de tester le %d et le %s", octal, str);

//%o 	octal integer
	printf(COLOR_GREEN "OCTAL INTEGER (o)\n" COLOR_RESET);
	printf("%o\n\n", max_unsigned);

//%u 	unsigned decimal integer
	printf(COLOR_RED "UNSIGNED DECIMAL INTEGER (u)\n" COLOR_RESET);
	printf("%u\n", min);
	printf("%u\n\n", max_unsigned);

//%x 	hexadecimal integer - ASCII
	printf(COLOR_GREEN "HEXADECIMAL INTEGER\n" COLOR_RESET);
	printf(COLOR_CYAN "   - LOWER (x)\n" COLOR_RESET);
	printf("%x\n", hexa);
	printf("%x\n", 'a'); //lower
	printf(COLOR_CYAN "   - UPPER (X)\n" COLOR_RESET);
	printf("%X\n\n", hexa);
	printf("%X\n", 'A'); //upper

//%c 	character (int to letter)
	printf(COLOR_RED "INT to LETTER ASCII (c)\n" COLOR_RESET);
   for( c = 75 ; c <= 80; c++ ) 
    printf("ASCII value = %d, Character = %c\n", c , c );

//%% 	Prints a % sign
	printf(COLOR_GREEN "PRINT THE %% SIGN\n" COLOR_RESET);
	printf("\n");
	printf("%%\n");

//		Another test ... RESULT : Affiche un %d seul
	printf("%%d\n", min);
	printf("%c\n\n"); //Affiche au pif (?!)

//		Minimum width integration
	printf(COLOR_RED "MINIMUM WIDTH (c)\n" COLOR_RESET);
	printf("%7s\n", "coucou"); // Right-Justification
	printf("%5s\n", "coucou"); // Right-Justification
	2 * printf("%-7s", "coucou"); // Left-Justification


return (0);
	

/* BONUS
Affiche un nombre en décimale (un argument)
	printf("%f\n",10.1); */
}

