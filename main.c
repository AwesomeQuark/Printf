#include <libc.h>
#include "ft_printf.h"

int		main()
{
	int nb[5];

	nb[0] = 666;
	ft_printf("Nombre : %d %p\n", nb[0], nb);
	ft_printf("j'ai %d grammes de %s dans la poche !", 2, "cocaine");
	ft_printf("\nJe consens a t'en %s la moitié, a condition que tu me %s une contrepartie seduisante... Disons, %i euros ?", "ceder", "fournisses", 100);
	ft_printf("\nTrying to print char A : %c", 65);
}
