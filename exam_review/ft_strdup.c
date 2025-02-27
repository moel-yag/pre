#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return i;
}

char	*ft_strdup(char *src)
{
	int i = 0;
	int len = ft_strlen(src) - 1;
	char *copy;

	copy = malloc(sizeof(char) * len + 1);
	if (!copy)
		return NULL;
	while (src[i])
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

int main()
{
	char	*a;
	a = "Hello World";
	printf("%s\n", ft_strdup(a));
}
