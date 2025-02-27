#include <unistd.h>

int	main(int ac, char **av)
{
	int i = 0;
	int tab[256] = {};
	while (av[1][i])
	{
		int j = 0;
		while (av[2][j])
		{
			if (av[1][i] == av[2][j] && !tab[(int)av[1][i]])
			{
				tab[(int)av[1][i]] = 1;
				write(1, &av[1][i], 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}
