/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 23:15:07 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/06 22:28:48 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <wchar.h>
#include <stdio.h>

static char	ft_help_four(t_all_flags all)
{
	char	sign;

	if (all.f_minus)
		sign = ' ';
	else
		sign = (char)(all.f_zero == 1 ? '0' : ' ');
	return (sign);
}

static char	*ft_help_five(char *src, char *width, t_all_flags all, char flag)
{
	char	*result;

	if (all.f_minus)
		result = ft_strjoin(src, width);
	else
		result = ft_strjoin(width, src);
	if (flag)
		free(src);
	free(width);
	return (result);
}

char		*ft_print_strings(char **f, t_all_flags all_flags, va_list list)
{
	char			*str;
	unsigned int	*arr;
	char			*temp;

	str = 0;
	if (**f == 'S' && MB_CUR_MAX == 4)
	{
		arr = (unsigned int*)va_arg(list, int*);
		if (arr == NULL)
			str = "(null)";
		else
			str = ft_create_ustring(arr, ft_strnew(0));
		temp = str;
		str = ft_make_width_str(str, all_flags, 0);
		free(temp);
	}
	else
	{
		str = va_arg(list, char*);
		if (str == NULL)
			str = "(null)";
		str = ft_make_width_str(str, all_flags, 0);
	}
	(*f)++;
	return (str);
}

char		*ft_make_width_str(char *src, t_all_flags all, char flag)
{
	char		sign;
	intmax_t	len;
	char		*result;
	char		*width;

	len = (int)ft_strlen(src);
	if (len > all.currency && all.dot && ++flag)
	{
		src = ft_strsub(src, 0, (size_t)all.currency);
		len = (int)ft_strlen(src);
	}
	if (len >= all.width)
	{
		if (flag)
			return (src);
		return (ft_strdup(src));
	}
	sign = ft_help_four(all);
	len = all.width - ft_strlen(src);
	width = ft_strnew((size_t)len);
	if (len > 0 && width)
		width = ft_memset(width, sign, (size_t)len);
	result = ft_help_five(src, width, all, flag);
	return (result);
}
