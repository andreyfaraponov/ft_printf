/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 21:27:29 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/04 21:27:47 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_get_flags(char **f, t_all_flags *all_flags)
{
	if (**f == '#')
		all_flags->f_sharp = 1;
	else if (**f == '+')
		all_flags->f_plus = 1;
	else if (**f == '-')
		all_flags->f_minus = 1;
	else if (**f == '0')
		all_flags->f_zero = 1;
	else if (**f == ' ')
		all_flags->f_space = 1;
	else
		return ;
	(*f)++;
	ft_get_flags(f, all_flags);
}

size_t		ft_get_number(char **f)
{
	size_t	nb;

	nb = 0;
	while (**f <= '9' && **f >= '0')
		nb = nb * 10 + *((*f)++) - '0';
	return (nb);
}

void		ft_get_size(char **f, t_all_flags *all_flags)
{
	if (!ft_strncmp(*f, "hh", 2) && ft_size_flags_null(all_flags) && (*f)++)
		all_flags->hh = 1;
	else if (**f == 'h' && ft_size_flags_null(all_flags))
		all_flags->h = 1;
	else if (!ft_strncmp(*f, "ll", 2) && ft_size_flags_null(all_flags) &&
			(*f)++)
		all_flags->ll = 1;
	else if (**f == 'l' && ft_size_flags_null(all_flags))
		all_flags->l = 1;
	else if (**f == 'j' && ft_size_flags_null(all_flags))
		all_flags->j = 1;
	else if (**f == 'z' && ft_size_flags_null(all_flags))
		all_flags->z = 1;
	else
		return ;
	(*f)++;
	ft_get_size(f, all_flags);
}

int			ft_size_flags_null(t_all_flags *all_flags)
{
	all_flags->hh = 0;
	all_flags->h = 0;
	all_flags->l = 0;
	all_flags->ll = 0;
	all_flags->j = 0;
	all_flags->z = 0;
	return (1);
}
