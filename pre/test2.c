#include <unistd.h>     // for sleep
#include <sys/signal.h> // for signals
#include <string.h>     // for memset
#include <stdlib.h>     // for exit

void    cleanup(int sigNum);

int main(int ac, char **av)
{
    struct sigaction act;
    int n;

    if (ac != 2)
    {
        fprintf(stderr, "Usage: %s <seconds>\n", av[0]);
        exit(1);
    }

    act.sa_handler = cleanup;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act, NULL);

    n = atoi(av[1]);
    printf("Sleeping for %d seconds...\n", n);
    sleep(n);
    printf("Done sleeping.\n");

    return 0;
}

void cleanup(int sigNum)
{
    (void) sigNum;
    printf("\nCaught SIGINT. Exiting...\n");
    exit(0);
}