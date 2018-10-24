/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:54:38 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/24 15:48:32 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	prepare_headers(void *link, size_t size)
{
	size_t			i;
	size_t			len;

	len = sizeof(t_zonehead);
	i = 0;
	ft_putnbr(len);
	write(1, "\nPREPARE HEADER 1\n", 18);
	ft_putnbr(getpagesize());
	write(1, "\n", 1);
	while (i <= size)
	{
		ft_putnbr(len);
		write(1, "\nPREPARE HEADER ", 16);
		ft_putnbr(i);
		write(1, "\n", 1);
		((t_zonehead *)link)->kind = NONE;
		((t_zonehead *)link)->fills = NULL;
		((t_zonehead *)link)->frees = NULL;
		((t_zonehead *)link)->next = link + len;
		link = link + len;
		i += len;
		write(1, "\n__PREPARE HEADER ", 18);
		ft_putnbr(i);
		write(1, "\n", 1);
	}
	write(1, "PREPARE HEADER 3\n", 17);
}

void	*ft_extend_allocs(size_t size)
{
	void			*addr;

	if ((addr = mmap(NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	prepare_headers(addr, size);
	return (addr);
}

void	*ft_init_malloc(void)
{
	t_zonehead	*master_header;

	if (g_masterhead != NULL)
		return (g_masterhead);
	if ((master_header = (t_zonehead *)mmap(NULL, getpagesize(),
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	master_header->kind = IS_MASTER;
	master_header->frees = (void *)master_header + sizeof(t_zonehead);
	master_header->next = NULL;
	master_header->fills = NULL;
//	prepare_headers(master_header->frees,
//			(size_t)getpagesize() - sizeof(t_zonehead));
	return (master_header);
}
