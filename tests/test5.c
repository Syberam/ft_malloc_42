#include "../includes/malloc.h"

int main()
{
	void	*ptr;

	ft_putendl(":::::::::::::::::::::::::::::::::::::::");
	ft_putendl(" TEST 5 START :");
	ft_putendl(":::::::::::::::::::::::::::::::::::::::\n");
	ptr = malloc(100);
	ptr = malloc(100);
	malloc(400);
	malloc(800);
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	ft_putendl("\n:::::::::::::::::::::::::::::::::::::::\n");
	ptr = realloc(ptr, 222);
	show_alloc_mem();
	ft_putendl("\n:::::::::::::::::::::::::::::::::::::::\n");
	ptr = realloc(ptr, 600);
	show_alloc_mem();
	ft_putendl("\n:::::::::::::::::::::::::::::::::::::::\n");
	return (0);
}
