#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int ac, char **av)
{
    int pid = fork();
    if (pid == -1)
        return -1;

    if (pid == 0)
    {
        // Child processing
        int err = execlp("ping", "ping", "-c", "1", "google.com", NULL);
        if (err == -1)
        {
            printf("Could not find program to execute!\n");
            return 0;
        }
    }
    else
    {
        // Parent processing
        wait(NULL);
        printf("Success!\n");
        printf("Some post processing goes here!\n");
    }

    return 0;
}