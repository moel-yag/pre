#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void	signal_handler(int signum)
{
	printf("Received SIGINT!", signum);
	exit 0;
}

int	main()
{
	signal(SIGINT, signal_handler);

}
