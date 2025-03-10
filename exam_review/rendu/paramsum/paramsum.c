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

int main(int ac, char **av)
{
    if (ac < 2)
    {
        write(1, "0\n", 2);
        return 0;
    }
    putnbr(ac -1);
    write(1, "\n", 1);
}