//
// Created by Andrey FARAPONOV on 12/17/17.
//

#ifndef FT_PRINTF_LIBFTPRINTF_H
# define FT_PRINTF_LIBFTPRINTF_H
# define ABS(x) x < 0 ? (-(x)) : x
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <inttypes.h>

char		*ft_strchr(const char *s, int c);
size_t		ft_strlen(const char *s);
int			ft_strncmp(char *s1, char *s2, size_t n);

typedef struct			s_all_flags
{
	char 		f_sharp;
	char		f_zero;
	char		f_minus;
	char 		f_plus;
	char		f_space;
	intmax_t	currency;
	int 		dot;
    intmax_t	width;
	char 		hh;
	char 		h;
	char 		l;
	char 		ll;
	char 		j;
	char		z;
	char 		large;
}						t_all_flags;

int 			ft_printf(const char *zzz, ...);
void			ft_all_flags_init(t_all_flags *flags);
void			ft_get_flags(char **f, 	t_all_flags	*all_flags);
size_t			ft_get_number(char **f);
void			ft_get_size(char **f, t_all_flags *all_flags);
int 			ft_main_print(char **f, t_all_flags flags, va_list list);
int 			ft_print_nums(char **f, t_all_flags all_flags,  va_list list);
char 		*ft_get_int(t_all_flags all, va_list list);
char		*ft_get_unsigned_any(char **f, t_all_flags all, va_list list);
char		*ft_get_unsigned(t_all_flags all, va_list list);
char 		*ft_itoa_base(uintmax_t num, char system, t_all_flags all);
char 		*ft_get_lint(t_all_flags all, va_list list);
char		*ft_numstr_make(char *src, t_all_flags all, int isneg);
char 		ft_get_sign(t_all_flags all, int isneg);
char		*ft_get_hex(t_all_flags all, va_list list, char system);
char		*ft_get_hex_any(char **f, t_all_flags all, va_list list, char system);
char		*ft_hex_make(char *src, t_all_flags all);
char		*ft_get_oct(t_all_flags all, va_list list, char system);
char		*ft_get_oct_any(char **f, t_all_flags all, va_list list, char system);
char		*ft_oct_make(char *src, t_all_flags all);
char		*ft_get_oct_sign(t_all_flags all);
char		*ft_get_hex_sign(t_all_flags all);
int 		ft_print_strings(char **f, t_all_flags all_flags,  va_list list);
char 		*ft_make_width_str(char *src, t_all_flags all);
int 		ft_print_characters(char **f, t_all_flags all_flags,  va_list list);
char 		*ft_make_width_char(char *src, t_all_flags all);
int 		ft_print_memory(char **f, t_all_flags all_flags, va_list list);
int			ft_size_flags_null(t_all_flags *all_flags);
int 		ft_print_percent(char **f, t_all_flags flags);
char		*ft_make_width(char *src, t_all_flags all);
t_all_flags	ft_if_dot(char **src, t_all_flags all, char *sign, int isneg);
char		*ft_putsign(char *src, char sign, t_all_flags all, int isneg);
char 		*ft_make_precision(char *src, t_all_flags all);

#endif
