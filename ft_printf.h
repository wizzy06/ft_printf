/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cparis <cparis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 23:48:48 by cparis            #+#    #+#             */
/*   Updated: 2017/03/18 15:07:56 by cparis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>
# include <wchar.h>
# include "libft/libft.h"
# include <stdint.h>

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

void		ft_print_is_char(t_conversion *conv, va_list ap);
void		ft_print_is_number(t_conversion *conv, va_list ap);
intmax_t    ft_get_number_signed(t_conversion *conv, va_list ap);
uintmax_t  	ft_get_number_unsigned(t_conversion *conv, va_list ap);
const char    	*ft_pos_or_neg(t_conversion *conv, const char *format);
const char    	*ft_init_param(const char *format, va_list ap);
char			*ft_itoa_base(uintmax_t value, uintmax_t base);
void			ft_print_char(t_conversion *conv, char c);
void			ft_print_str(t_conversion *conv, char *str);
void        ft_print_du(t_conversion *conv, uintmax_t nbr);
void        ft_print_o(t_conversion *conv, uintmax_t nbr);
void		ft_print_xp(t_conversion *conv, uintmax_t nbr);
void		ft_print_x_caps(t_conversion *conv, uintmax_t nbr);
void			ft_print_wchar(t_conversion *conv, wint_t wint);
void			ft_print_wstr(t_conversion *conv, wchar_t *wstr);
void		    ft_print_space(int len, int min, char c);
void		    ft_print_number_with_space(t_conversion *conv, char *str);
void		    ft_true_print(void *mem, int size);
int				ft_count_octet(int option, int add);
int				ft_printf(const char *format, ...);
t_conversion	*reset_conv(void);
char			*free_join(char *s1, char *s2);
void	ft_wintoa(wint_t wint);
int		ft_start_print(const char *format, va_list ap);
char	*ft_strupcase(char *str);
char	*ft_strlowcase(char *str);
void		ft_check_type(t_conversion *conv);
char		ft_choose_camp(t_conversion *conv, va_list ap);
void	ft_print_type(t_conversion *conv, va_list ap);

#endif


