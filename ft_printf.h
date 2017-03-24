/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 14:08:42 by maleroy           #+#    #+#             */
/*   Updated: 2017/03/24 19:26:18 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <wchar.h>
# include "libft/libft.h"

typedef struct			s_flags
{
	int					pound;
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
	int					prec_set;
	t_modifier			modif;
	char				type;
	char				sign;
}						t_conversion;

int						ft_printf(const char *format, ...);
int						ft_count_octet(int option, int add);
const char				*ft_prep_print(const char *format, va_list ap);
void					ft_print_type(t_conversion *conv, va_list ap);
intmax_t				ft_get_num_signed(t_conversion *conv, va_list ap);
uintmax_t				ft_get_num_unsigned(t_conversion *conv, va_list ap);
void					ft_print_spacing(int len, int min, char c);
void					ft_print_num_spaced(t_conversion *conv, char *str);
void					ft_true_print(void *mem, int size);
void					ft_print_du(t_conversion *conv, uintmax_t num);
void					ft_print_o(t_conversion *conv, uintmax_t num);
void					ft_print_xp(t_conversion *conv, uintmax_t num);
void					ft_print_x_caps(t_conversion *conv, uintmax_t num);
t_conversion			*ft_reset_conv(void);
char					*ft_free_join(char *s1, char *s2);
void					ft_print_char(t_conversion *conv, char c);
void					ft_print_string(t_conversion *conv, char *str);
void					ft_print_wchar(t_conversion *conv, wint_t wint);
void					ft_print_wstr(t_conversion *conv, wchar_t *wstr);
void					ft_wintoa(wint_t wint);
char					*ft_itoa_base(uintmax_t value, uintmax_t base);

#endif
