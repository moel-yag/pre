#include <stdio.h>
#include <string.h>

size_t	ft_strspn(const char *s, const char *charset)
{
	size_t i = 0;

	while (s[i])
	{
		int j = 0;
		int check = 0;
		while (charset[j])
		{
			if (s[i] == charset[j])
				check = 1;
			j++;
		}
		if (check == 0)
			return i;
		i++;
	}
	return i;
}

int main(int ac, char **av)
{
	printf("%zu\n", ft_strspn(av[1], av[2]));
	printf("%zu\n", strspn(av[1], av[2]));
}
