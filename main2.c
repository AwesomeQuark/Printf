#include "includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <time.h>

static void	test(int (*f)(const char *str, ...), int type)
{
	int max_val = 2000000;
	int i = 2147483647;
	long l = 2147483647;
	long long ll = 9223372036854775807;
	char c = 0;
	intmax_t im = 9223372036854775807;
	if (type == 1)
		for (int i = 0; i < max_val; i++)
		{
			f("\n");
			f("%%\n");
			f("%d\n", 42);
			f("%d%d\n", 42, 41);
			f("%d%d%d\n", 42, 43, 44);
			f("%ld\n", l);
			f("%lld\n", ll);
			f("%x %X %p %20.15d\n", 505, 505, &ll, 54321);
			f("%-10d % d %+d %010d %hhd\n", 3, 3, 3, 1, c);
			f("%d %d %u %o %#08x\n", 546453465, 6544, i, 40, 42);
			f("%x %#X %s%s\n", 1000, 1000, "test", "test2");
			f("%s%s%s\n", "test", "test", "test");
		}
	
	else
	{
		for (int i = 0; i < max_val / 3; i++)
		{
			f("ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd %s%s%s%s", "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd", "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd", "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd" , "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd");
		}
	}
	
}

int main()
{
	time_t time1;
	time_t time2;
	time_t time3;
	float diff1;
	float diff2;

	time1 = time(NULL);
	test(printf, 1);
	time2 = time(NULL);
	test(ft_printf, 1);
	time3 = time(NULL);
	diff1 = (difftime(time2, time1));
	diff2 = (difftime(time3, time2));
	/*time1 = time(NULL);
	test(printf, 2);
	time2 = time(NULL);
	test(ft_printf, 2);
	time4 = time(NULL);*/
	printf("\n\n==== FIRST TEST : Simple variables, flags and short calls ====\n");
	printf("Your function speedrate : %d%%\n", (int)((diff1 * 100) / diff2));
	printf("Exec time original : %d yours : %d", (int)diff1, (int)diff2);
	printf("\n\n==== SECOND TEST : long long shit and calls to strings ====\n");
	printf("Your function speedrate : %d%%\n", (int)((difftime(time3, time2) * 100) / difftime(time2, time1)));
	return (0);
}