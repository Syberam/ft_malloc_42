# include "../includes/malloc.h"
# include "../includes/libft.h"

int main()
{
	int i;
	char *addr;
	ft_putendl(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	ft_putendl(" START TEST 7 ");
	ft_putendl(":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::");
	i = 0;
	while (i < 65)
	{
		malloc(0);
		addr = realloc(NULL, 33);
		realloc(addr, 90);
		realloc(addr, 3000);
		realloc(addr, 0);
		calloc(5, 10);
		if (i % 15)
			free(addr);
		i++;
	}
	return (0);
}
