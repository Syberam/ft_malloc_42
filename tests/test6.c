#include "malloc.h"

int main()
{
	int i;
	char *addr;
	char **ptr;

	ft_putendl("");
	ft_putendl(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	ft_putendl("");
	ft_putendl(" TEST 6 START :");
	ft_putendl("");
	ft_putendl(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	ft_putendl("");
	i = 0;
	while (i < 300)
	{
		addr = (char*)malloc(1024);
		addr[0] = 42;
		free(addr);
		i++;
	}
	i = 0;
	ptr = (char **)malloc(2000);
	while (i < 2)
	{
		ptr[i] = (char *)malloc(8000);
		ptr[i][0] = 42;
		i++;
	}
	free(ptr[0]);
	while (i < 30)
	{
		ptr[i] = (char *)malloc(8000);
		ptr[i][0] = 42;
		i++;
	}
	while (i < 2000)
	{
		ptr[i] = (char *)malloc(8000);
		ptr[i][0] = 42;
		free(ptr[i]);
		i++;
	}
	return (0);
}
