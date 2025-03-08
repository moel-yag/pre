#include <unistd.h>

void    to_lower(char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}
void    str_capitalizer(char *str)
{
    int i = 0;
    while (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            write(1, &str[i++], 1);
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] -= 32;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            write(1, &str[i++], 1);
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            write(1, &str[i++], 1);
    }
}

int main(int ac, char **av)
{
    if (ac < 2)
    {
        write(1, "\n", 1);
        return 0;
    }
    int arg= 1;
    while (arg < ac)
    {
        to_lower(av[arg]);
        str_capitalizer(av[arg]);
        write(1, "\n", 1);
        arg++;
    }
}