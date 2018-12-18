#include <libc.h>
#include "includes/ft_printf.h"


static void	test(int (*f)(const char *str, ...))
{
	int nb[5];

	nb[0] = 666;
	f("Pointeur : %p\n", nb);
	f("String : %s\n", "Brule un bebe");
	f("Integers : %--25d %i\n", -2147483648, 42);
	f("Integers base : %o (octal) %x(hexamin) %X(hexamaj)\n", nb[0], nb[0], nb[0], nb[0]);
	f("Integers flags : %ld (l) %lld (ll) %hd (h) %hhd (hh)\n", 666, 666, 666, 665);
	f("Trying to print char A : %c\n", 65);
	f("Pourcent : %% with flags : %25%\n");
	f("Float : %f with precision : %f\n", 45.25, 88.54);
	f("Custom %Zoooo\n", "oui");
}

int		main()
{
	printf("\n====  TEST PRINTF ORIGINAL  ====\n");
	test(&printf);
	printf("\n====  TEST PRINTF PERSONNEL ====\n");
	test(&ft_printf);
}