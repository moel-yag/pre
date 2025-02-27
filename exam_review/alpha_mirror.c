#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int	i = 0;
	char	res;

	while (av[1][i])
	{
		if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			res = 'A' - av[1][i] + 'Z';
		else if (av[1][i] >= 'a' && av[1][i] <= 'z')
			res = 'a' - av[1][i] + 'z';
		else
			res = av[1][i];
		write(1, &res, 1);
		i++;
	}
	write(1, "\n", 1);
}
