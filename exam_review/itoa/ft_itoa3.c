#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char    *ft_itoa(int nbr)
{
    char *str;
    char *t;
    char *u;

    if (!(str = (char *)malloc(16)))
        return (NULL);
    t = str;
    (nbr < 0 ? *t++ = '-' : 1);
    if (nbr > 0)
        nbr = -nbr;
    if (nbr <= -10)
    {
        u = ft_itoa(-(nbr / 10));
        while (*u)
            *t++ = *u++;
    }
    *t = '0' - nbr % 10;
    *(t + 1) = '\0';
    return (str);
}

int main()
{
    int test_numbers[] = {123, -123, 0, 42, -2147483648};
    int num_tests = 5;

    for (int i = 0; i < num_tests; i++)
    {
        int num = test_numbers[i];
        char *str = ft_itoa(num);
        printf("ft_itoa(%d) = %s\n", num, str);

        if (str != "0")
            free(str);
    }
    return 0;
}
