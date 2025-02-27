#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char	**ft_split(char *str)
{
    int i = 0;
    int j = 0;
    int index = 0;
    int start = 0;
    char **return_str = malloc(1000 * sizeof(char *));
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
            i++;
        if (!str[i])
            break;
        while ((size_t)start < strlen(str) && str[start] && (str[start] == ' ' || str[start] == '\t' || str[start] == '\n'))
            start++;
        while (str[i] && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            i++;
        return_str[j] = malloc(1000);
        index = 0;
        while (start < i)
        {
            return_str[j][index] = str[start];
            index++;
            start++;
        }
        return_str[j][index] = '\0';
        j++;
    }
    return_str[j] = NULL;
    return (return_str);
}

// int main()
// {
//     char **str = ft_split("  starting and ending   ");
//     int i = 0;
//     while (str[i] && i < 5)
//     {
//         printf("%s\n", str[i]);
//         free(str[i]);
//         i++;
//     }
//     free(str);
// }
