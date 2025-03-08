#include <stdio.h>
#include <unistd.h>
#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t  i = 0;
    while (s[i])
    {
        int j = 0;
        while (reject[j])
        {
            if (s[i] == reject[j])
                return i;
            j++;
        }
        i++;
    }
        return i;
}

// int main(int ac, char **av)
// {
//     if (ac < 2)
//         return 0;
//     printf("%ld\n", ft_strcspn(av[1], av[2]));
//     printf("%ld\n", strcspn(av[1], av[2]));
// }