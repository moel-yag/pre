#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bit;
	while (i--)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
	}
}

int	main(int ac, char **av)
{
	char octet = 2;
	print_bits(octet);
	write(1, "\n", 1);
}
