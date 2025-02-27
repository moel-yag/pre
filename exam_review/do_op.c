#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	
	if (av[2][0] == '*')
		printf("%d\n", atoi(av[1]) * atoi(av[3]));
	if (av[2][0] == '/')
		printf("%d\n", atoi(av[1]) / atoi(av[3]));
	if (av[2][0] == '+')
		printf("%d\n", atoi(av[1]) + atoi(av[3]));
	if (av[2][0] == '-')
		printf("%d\n", atoi(av[1]) - atoi(av[3]));
	if (av[2][0] == '%')
		printf("%d\n", atoi(av[1]) % atoi(av[3]));
}
