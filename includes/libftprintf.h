/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:17:22 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/06 20:32:50 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_LIBFTPRINTF_H
# define FT_PRINTF_LIBFTPRINTF_H
# define ABS(x) x < 0 ? (-(x)) : x
# define M1_ONE(chr) (unsigned char)(((chr << 21) >> 27) | 192)
# define M1_TWO(chr) (unsigned char)(((chr << 26) >> 26) | 128)
# define M2_ONE(chr) (unsigned char)(((chr << 12) >> 24) | 224)
# define M2_TWO(chr) (unsigned char)(((chr << 20) >> 26) | 128)
# define M3_ONE(chr) (unsigned char)(((chr << 11) >> 29) | 240)
# define M3_TWO(chr) (unsigned char)(((chr << 14) >> 26) | 128)
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <inttypes.h>
# include "../libft/libft.h"

typedef struct	s_all_flags
{
	char		f_sharp;
	char		f_zero;
	char		f_minus;
	char		f_plus;
	char		f_space;
	intmax_t	currency;
	int			dot;
	intmax_t	width;
	char		hh;
	char		h;
	char		l;
	char		ll;
	char		j;
	char		z;
	char		large;
}				t_all_flags;

int				ft_printf(const char *zzz, ...);
void			ft_all_flags_init(t_all_flags *flags);
void			ft_get_flags(char **f, t_all_flags *all_flags);
size_t			ft_get_number(char **f);
void			ft_get_size(char **f, t_all_flags *all_flags);
int				ft_main_print(char **f, t_all_flags flags, va_list list,
	int *r);
char			*ft_print_nums(char **f, t_all_flags all_flags, va_list list);
char			*ft_get_int(t_all_flags all, va_list list);
char			*ft_get_unsigned_any(char **f, t_all_flags all, va_list list);
char			*ft_get_unsigned(t_all_flags all, va_list list);
char			*ft_itoa_base(uintmax_t num, char system, t_all_flags all);
char			*ft_get_lint(t_all_flags all, va_list list);
char			*ft_numstr_make(char *src, t_all_flags all, int min, char s);
char			ft_get_sign(t_all_flags all, int isneg);
char			*ft_get_hex(t_all_flags all, va_list list, char system);
char			*ft_get_hex_any(char **f, t_all_flags all, va_list list,
	char system);
char			*ft_hex_make(char *src, t_all_flags all, int cmp_result);
char			*ft_get_oct(t_all_flags all, va_list list, char system);
char			*ft_get_oct_any(char **f, t_all_flags all, va_list list,
	char system);
char			*ft_oct_make(char *src, t_all_flags all);
char			*ft_get_oct_sign(t_all_flags all);
char			*ft_get_hex_sign(t_all_flags all);
char			*ft_print_strings(char **f, t_all_flags all_flags,
	va_list list);
char			*ft_make_width_str(char *src, t_all_flags all, char f);
int				ft_print_characters(char **f, t_all_flags all_flags,
	va_list list);
char			*ft_make_width_char(char *src, t_all_flags all);
char			*ft_print_memory(char **f, t_all_flags all_flags, va_list list);
int				ft_size_flags_null(t_all_flags *all_flags);
char			*ft_print_percent(char **f, t_all_flags flags);
char			*ft_make_width(char *src, t_all_flags all);
t_all_flags		ft_if_dot(char **src, t_all_flags all, char *sign, int isneg);

int				ft_print_u_characters(char **f, t_all_flags all_flags,
	va_list list);

char			*ft_putsign(char *src, char sign, t_all_flags all, int isneg);
char			*ft_make_precision(char *src, t_all_flags all);
void			ft_unicode_write(unsigned int chr);
int				ft_max_bit_size(unsigned int n);
char			*ft_create_ustring(unsigned int *arr, char *src);
int				ft_print_null(char chr, t_all_flags all_flags);

#endif
