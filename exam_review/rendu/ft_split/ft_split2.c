#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

char    **ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int start = 0;
    int index = 0;
    char **return_res = malloc(1000 * sizeof(char *));

    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (!str[i])
            break;
        start = i;
        while (str[i] && !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        return_res[j] = malloc(1000);
        index = 0;
        while (start < i)
            return_res[j][index++] = str[start++];
        return_res[j][index] = '\0';
        j++;
    }
    return_res[j] = NULL;
    return (return_res);
}
int main()
{
    char **str = ft_split("  starting and ending   ");
    int i = 0;
    while (str[i] && i < 5)
    {
        printf("%s\n", str[i]);
        free(str[i]);
        i++;
    }
    free(str);
}

// int main()
// {
//     char str[] = "Hello from 1337 school";
//     char **res = ft_split(str);
//     int i = 0;
//     while (res[i] && i < 4)
//     {
//         printf("%s\n", res[i]);
//         free(res[i]);
//         i++;
//     }
//     free(res);
//     return 0;
// }