#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i = 0;
	int len = ft_strlen(av[1]);
	char *res;

	res = malloc(len * sizeof(char));
	while (av[1][i])
	{
		if (av[1][i] == '_')
		{
			i++;
			av[1][i] = av[1][i] - 32;
		}
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return 0;
}
