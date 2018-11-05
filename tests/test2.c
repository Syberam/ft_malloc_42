#include "malloc.h"

int main()
{
	int i;
	char *addr;

	ft_putendl("");
	ft_putendl(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	ft_putendl("");
	ft_putendl(" TEST 2 START :");
	ft_putendl("");
	ft_putendl("");
	i = 0;
	while (i < 1024)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	return (0);
}
