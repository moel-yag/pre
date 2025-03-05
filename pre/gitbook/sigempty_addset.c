#include <signal.h>

int	main()
{
	sigset_t	signal_set;

	sigemptyset(&signal_set);
	sigaddset(&signal_set, SIGINT);
}
