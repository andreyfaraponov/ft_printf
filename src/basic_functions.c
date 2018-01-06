/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:21:49 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/07 00:21:05 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_get_widthlen(char **f, va_list list)
{
	if (**f == '*')
	{
		(*f)++;
		return (va_arg(list, int));
	}
	else if (ft_strchr("0123456789", **f))
		return (ft_get_number(f));
	else
		return (0);
}

int			ft_calcandprint(char **f, va_list list)
{
	t_all_flags	all_flags;
	int			result;

	result = 0;
	ft_all_flags_init(&all_flags);
	if (**f && ft_strchr("#+-0 ", **f))
		ft_get_flags(f, &all_flags);
	if (**f && ft_strchr("0123456789*", **f))
		all_flags.width = ft_get_widthlen(f, list);
	if (**f && ft_strchr(".", **f) && (*f)++ && ++all_flags.dot)
		all_flags.currency = ft_get_widthlen(f, list);
	if (**f && ft_strchr("hljz", **f))
		ft_get_size(f, &all_flags);
	return (ft_main_print(f, all_flags, list, &result));
}

int			ft_main_print(char **f, t_all_flags flags, va_list list, int *res)
{
	char	*mb_res;

	mb_res = 0;
	if (**f && ft_strchr("dDioOuUxX", **f))
		mb_res = ft_print_nums(f, flags, list);
	else if (**f && ft_strchr("sS", **f))
		mb_res = ft_print_strings(f, flags, list);
	else if (**f && ft_strchr("cC", **f))
		return (ft_print_characters(f, flags, list));
	else if (**f == 'p')
		mb_res = ft_print_memory(f, flags, list);
	else if (**f == '%')
		mb_res = ft_print_percent(f, flags);
	else if (**f)
	{
		mb_res = ft_make_width(ft_strsub(*f, 0, 1), flags);
		(*f)++;
	}
	if (mb_res)
	{
		*res = (int)write(1, mb_res, ft_strlen(mb_res));
		free(mb_res);
	}
	return (*res);
}

int			ft_print_printf(char **f, va_list list, int *result)
{
	char	*tmp;

	tmp = ft_strchr(*f, '%');
	if (*f < tmp)
	{
		*result += write(1, *f, tmp - *f);
		return (ft_print_printf(&tmp, list, result));
	}
	else if (**f == '%')
	{
		(*f)++;
		*result += ft_calcandprint(f, list);
		return (ft_print_printf(f, list, result));
	}
	return (*result + (int)write(1, *f, ft_strlen(*f)));
}

int			ft_printf(const char *format, ...)
{
	va_list	list;
	int		result;

	result = 0;
	va_start(list, format);
	result = ft_print_printf((char**)&format, list, &result);
	va_end(list);
	return (result);
}
