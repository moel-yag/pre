#include <stdio.h>
#include <unistd.h>
#include <sys/signal.h>
#include <string.h>
#include <stdlib.h>

int x = 100;

void    signal_handler(int sig)
{
    x += 5;
    printf("x = %d\n", x);
}

void    signal_handler2(int sig)
{
    x += 10;
    printf("x = %d\n", x);
}

void    signal_handler3(int sig)
{
    x += 20;
    printf("x = %d\n", x);
}

int main()
{
    struct sigaction act;
    int i;

    memset(&act, 0, sizeof(act));
    act.sa_handler = signal_handler;
    sigaction(SIGUSR1, &act, NULL);

    memset(&act, 0, sizeof(act));
    act.sa_handler = signal_handler2;
    sigaction(SIGUSR2, &act, NULL);

    memset(&act, 0, sizeof(act));
    act.sa_handler = signal_handler3;
    sigaction(SIGUSR3, &act, NULL);

    while (1)
    {
        printf("x = %d\n", x);
        sleep(1);
    }

    return 0;
}