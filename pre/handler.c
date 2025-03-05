#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void    handle_sigtstp(int sig)
{
    printf("\nStop not allowed\n");
}

void    handle_sigcont(int dig)
{
    printf("Input Number: ");
    fflush(stdout);
}

int main(int ac, char **av)
{
    struct sigaction sa;
    sa.sa_handler = &handle_sigtstp;
    sa.sa_flags = SA_RESTART;
    // signal(SIGTSTP, &handle_sigtstp);
    // sigaction(SIGTSTP, &sa, NULL);
    // sigaction(SIGINT, &sa, NULL);
    sigaction(SIGCONT, &sa, NULL);

    int x;
    printf("Input number: ");
    scanf("%d", &x);
    printf("Result of: %d * 5 = %d\n", x, x*5);
    return 0;
}