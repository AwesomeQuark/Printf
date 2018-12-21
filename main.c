/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: conoel <conoel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 17:44:12 by conoel            #+#    #+#             */
/*   Updated: 2018/12/21 20:09:17 by conoel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include "includes/ft_printf.h"

static void	test(int (*f)(const char *str, ...))
{
	int	nb[5];

	nb[0] = 666;
	/*f("Pointeur : %p\n", nb);
	f("String : %s\n", "Brule un bebe");
	f("Integers : %+5d %i\n", 214648, 42);
	f("Integers base : %o (octal) %x(hexamin) %X(hexamaj)\n", 6, nb[0],
		nb[0], nb[0]);
	f("Integers flags : %ld (l) %lld (ll) %hd (h) %hhd (hh)\n", 666, 666, 666,
		665);
	f("Trying to print char A : %c\n", 0);
	f("Pourcent : %% with flags : %02%\n");
	f("Float : %lf with precision : %.5f\n", 45.25666666, 88.5);
	f("zero integers : %.0x %.2x\n", 0, 0);
	f(" %-5.-2s empty string bitch\n", "test");
	f("Octal : %-10.5d\n", 45);*/
	f("Pointeur : %p\n", nb);
	f("Integers :%#o %010x %52.8da\n", 666, 69, 42);
	f("String : %s %5s %.2s", "oui", "baaaa", "derision");
}

int			main(void)
{
	printf("\n====  TEST PRINTF ORIGINAL  ====\n");
	test(&printf);
	printf("\n====  TEST PRINTF PERSONNEL ====\n");
	test(&ft_printf);
}
