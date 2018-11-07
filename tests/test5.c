#include "malloc.h"

int main()
{
	ft_putendl(":::::::::::::::::::::::::::::::::::::::");
	ft_putendl(" TEST 5 START :");
	ft_putendl(":::::::::::::::::::::::::::::::::::::::");
	malloc(1024);
	malloc(5);
	malloc(111);
	malloc(1024 * 32);
	malloc(1024 * 64);
	malloc(11111);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}
