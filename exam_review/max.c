#include <stdio.h>

int	max(int *tab, unsigned int len)
{
	int i = 0;
	int tm = 0;
	while (i < len)
	{
		if (tm < tab[i])
			tm = tab[i];
		i++;
	}
	return tm;
}

int	main(int ac, char **av)
{
	int tab[] = {-5, 4, 0, 1, 3, 2};
	printf("%d\n", max(tab, 6));
}
