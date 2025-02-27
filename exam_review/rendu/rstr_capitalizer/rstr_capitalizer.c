#include <unistd.h>
#include <stdio.h>

void	to_lower(char *str)
{
	int i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
}

int	main(int ac, char *av[])
{
	if (ac < 2)
	{
		write(1, "\n", 1);
		return 0;
	}
	int i;
	int arg = 1;

	while (arg < ac)
	{
		to_lower(av[arg]);
		i = 0;
		while (av[arg][i])
		{
			while (av[arg][i] && av[arg][i] == ' ')
			{
				write(1, &av[arg][i], 1);
				i++;
			}
			while (av[arg][i] && av[arg][i] != ' ')
			{
				if (av[arg][i] >= 'a' && av[arg][i] <= 'z' && (av[arg][i+1] == ' '
				|| av[arg][i+1] == '\0'))
				{
					av[arg][i] -= 32;
					write(1, &av[arg][i], 1);
				}
				else
					write(1, &av[arg][i], 1);
				i++;	
			}
		}
		if (arg + 1 < ac)
			write(1, "\n", 1);
		arg++;
	}
	write(1, "\n", 1);
	return 0;
}
