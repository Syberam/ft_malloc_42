#include "../includes/malloc.h"
#include <stdio.h>

int main()
{
	int i;
	char *addr;

	i = 0;
	printf("getpagesize : %d\n", getpagesize());
	printf("TINY_ZONE : %d\n", TINY_ZONE);
	printf("SMAL_ZONE : %d\n", SMALL_ZONE);
	printf("TINY : %d\n", TINY);
	printf("SMALL : %d\n", SMALL);

	while (i < 1024)
	{
		i++;
	}
	return (0);
}
