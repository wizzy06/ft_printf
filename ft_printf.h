/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:48:48 by cparis            #+#    #+#             */
/*   Updated: 2017/03/06 15:23:16 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include "libft/libft.h"
#include "srcs/color_picker.c"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stddef.h>

typedef struct			s_flags
{
	int					sharp;
	int					zero;
	int					minus;
	int					plus;
	int					space;
}						t_flags;

typedef enum			e_modifier
{
	NONE, HH, H, LL, L, J, Z
}						t_modifier;

typedef struct			s_conversion
{
	t_flags				*flag;
	int					min_width;
	int					precision;
	t_modifier			modif;
	char				type;
	char				sign;
}						t_conversion;

static t_flags  *reset_flag(void);
t_conversion    *reset_conv(void);
char          *free_join(char *s1, char *s2);
char            *ft_init_param(t_conversion *conv, const char *format);

int		        ft_printf(const char *format, ...);
int             ft_hexa_upper(long int	decimal_nbr, int up_low);
void	        ft_hexa_lower(char c); 
int	            ft_int_to_octal(long nbr);
void            ft_conversion_master (va_list ap, const char format);
void            ft_pointer_adress(void *ptr);
void	        ft_minimum_width(va_list ap, const char *format);


/* 
void					print_type(t_conversion *conv, va_list ap);
intmax_t				get_num_signed(t_conversion *conv, va_list ap);
uintmax_t				get_num_unsigned(t_conversion *conv, va_list ap);
void					print_spacing(int len, int min, char c);
void					print_num_spaced(t_conversion *conv, char *str);
void					true_print(void *mem, int size);
void					print_du(t_conversion *conv, uintmax_t num);
void					print_o(t_conversion *conv, uintmax_t num);
void					print_xp(t_conversion *conv, uintmax_t num);
void					print_x_caps(t_conversion *conv, uintmax_t num);
char					*ft_itoa_base(uintmax_t value, uintmax_t base);
void					print_char(t_conversion *conv, char c);
void					print_string(t_conversion *conv, char *str);
void					print_wchar(t_conversion *conv, wint_t wint);
void					print_wstr(t_conversion *conv, wchar_t *wstr);
void					wintoa(wint_t wint);



int						count_octet(int option, int add);
*/ 

#endif


