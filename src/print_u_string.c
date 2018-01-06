/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:28:56 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/06 22:49:16 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

static char	*ft_strcharjoin(char *s1, unsigned char chr)
{
	char	*temp_one;
	char	*result;

	temp_one = ft_strnew(1);
	ft_memset(temp_one, chr, 1);
	result = ft_strjoin(s1, temp_one);
	free(temp_one);
	free(s1);
	return (result);
}

static char	*ft_u_save_large(unsigned int chr, char *src)
{
	char	*res;

	res = ft_strcharjoin(src, M3_ONE(chr));
	res = ft_strcharjoin(res, M3_TWO(chr));
	res = ft_strcharjoin(res, M2_TWO(chr));
	res = ft_strcharjoin(res, M1_TWO(chr));
	free(src);
	return (res);
}

static char	*ft_unicode_save(unsigned int chr, char *src)
{
	char				*res;

	if (ft_max_bit_size(chr) < 8)
		return (ft_strcharjoin(src, chr));
	else if (ft_max_bit_size(chr) < 12)
	{
		res = ft_strcharjoin(src, M1_ONE(chr));
		res = ft_strcharjoin(res, M1_TWO(chr));
	}
	else if (ft_max_bit_size(chr) < 17)
	{
		res = ft_strcharjoin(src, M2_ONE(chr));
		res = ft_strcharjoin(res, M2_TWO(chr));
		res = ft_strcharjoin(res, M1_TWO(chr));
	}
	else if (ft_max_bit_size(chr) < 22)
		return (ft_u_save_large(chr, src));
	return (res);
}

char		*ft_create_ustring(unsigned int *arr, char *src)
{
	while (*arr != 0)
	{
		src = ft_unicode_save(*arr, src);
		arr++;
	}
	return (src);
}
