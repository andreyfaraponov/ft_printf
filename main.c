/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afarapon <afarapon@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:33:47 by afarapon          #+#    #+#             */
/*   Updated: 2018/01/07 00:35:08 by afarapon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libftprintf.h"
#include <stdio.h>
#include <locale.h>

int		main(void)
{	
//	setlocale(LC_ALL, "");
	// ft_printf("%015S\n", L"Привет мир!");
	// ft_printf("%015.2S\n", L"Привет мир!");
	// ft_printf("%015.15S\n", L"Привет мир!");
	// ft_printf("%025.15S\n", L"Привет мир!");
	// ft_printf("%25.15S\n", L"Привет мир!");
	// ft_printf("%25.2S\n", L"Привет мир!");
	// ft_printf("%025.2S\n", L"Привет мир!");
	// ft_printf("%2S\n", L"Привет мир!");
	// ft_printf("%0.2S\n", L"Привет мир!");
	// ft_printf("%0.15S\n", L"Привет мир!");
	// ft_printf("%.15S\n", L"Привет мир!");
	// ft_printf("%02C\n", L'П');
	// ft_printf("%05C\n", L'П');
	// ft_printf("%05.10C\n", L'П');
	// ft_printf("%05.2C\n", L'П');
	// ft_printf("%015.1C\n", L'П');
	// printf("1: %d\n", printf("%C\n", L'П'));
	// printf("2: %d\n", ft_printf("%C\n", L'П'));
	// printf("1: %d\n", printf("%02C\n", L'П'));
	// printf("2: %d\n", ft_printf("%02C\n", L'П'));
	// printf("1: %d\n", printf("%05C\n", L'П'));
	// printf("2: %d\n", ft_printf("%05C\n", L'П'));
	// printf("1: %d\n", printf("%05.10C\n", L'П'));
	// printf("2: %d\n", ft_printf("%05.10C\n", L'П'));
	// printf("1: %d\n", printf("%05.2C\n", L'П'));
	// printf("2: %d\n", ft_printf("%05.2C\n", L'П'));
	// printf("1: %d\n", printf("%015.1C\n", L'П'));
	// printf("2: %d\n", ft_printf("%015.1C\n", L'П'));
	// printf("1: %d\n", printf("1 char:%C\n", 0));
	// printf("2: %d\n", ft_printf("2 char:%C\n", 0));
	// printf("1: %d\n", printf("1 char:%c\n", 0));
	// printf("2: %d\n", ft_printf("2 char:%c\n", 0));
	// printf("%S\n", "@@");
	// ft_printf("%S", "@@");
	 printf("%S\n", L"Lalalala, 100% des gens qui parlent à Ly adorent Ly. Ou Presque. 2, 10, 2710,");
	 ft_printf("%S\n", L"Lalalala, 100% des gens qui parlent à Ly adorent Ly. Ou Presque. 2, 10, 2710,");
	// printf("%.2S\n", L"@@");
	// ft_printf("%.2S\n", L"@@");
	// ft_printf("%2S\n", L"@@");
	// ft_printf("%S\n", NULL);
	// printf("%.4O", 42);
	// printf("%d\n", printf("%.5S\n", L"При"));
	// printf("%d\n", ft_printf("%.5S\n", L"При"));
	 printf("%.2S\n", L"@@@");
	 ft_printf("%.2S\n", L"@@@");


	return (0);
}
