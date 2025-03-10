#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    putnbr(int nb)
{
    if (nb == -2147483648)
        write(1, "-2147483648", 11);
    else
    {
        if (nb < 0)
        {
            nb = -nb;
            write(1, "-", 1);
        }
        if (nb >= 0 && nb <= 9)
            ft_putchar(nb + '0');
        if (nb > 9)
        {
            putnbr(nb/10);
            ft_putchar(nb % 10 + '0');
        }
    }
}

int main()
{
    int i = 1;
    while (i <= 100)
    {
        if (i % 3 == 0 && i % 5 == 0)
            write(1, "fizzbuzz", 8);
        else if (i % 3 == 0)
            write(1, "fizz", 4);
        else if (i % 5 == 0)
            write(1, "buzz", 4);
        else
            putnbr(i);
        write(1, "\n", 1);
        i++;
    }
}