#include <stdio.h>
#include <stdlib.h>

int	is_power_of_2(unsigned int n)
{
	int res;
	res = n;
	while ((res / 2) > 9)
		res /= 2;
	if (res%2 == 0)
		return 1;
	return 0;
}

int	main(int ac, char **av)
{
	printf("%d\n", is_power_of_2((unsigned int)atoi(av[1])));
}
