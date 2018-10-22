/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:54:38 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/22 17:52:35 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	prepare_headers(void *link)
{
	size_t			i;
	size_t			len;

	len = sizeof(t_zonehead);
	i = 0;
	while (i < TINY_ZONE)
	{
		((t_zonehead *)link)->kind = NONE;
		((t_zonehead *)link)->fills = NULL;
		((t_zonehead *)link)->frees = NULL;
		((t_zonehead *)link)->next = link + len;
		link = link + len;
		i += len;
	}
}

void	*ft_extend_allocs(void)
{
	void			*addr;

	if (!(addr = mmap(NULL, TINY_ZONE,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)))
		return (NULL);
	prepare_headers(addr);
	return (addr);
}

void	*ft_init_malloc(void)
{
	t_zonehead		*master_header;
	void			*addr;

	if (g_masterhead != NULL)
		return g_masterhead;
	if (!(addr = mmap(NULL, TINY_ZONE,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)))
		return (NULL);
	ft_bzero(addr, TINY_ZONE);
	master_header = (t_zonehead *)addr;
	master_header->kind = IS_MASTER;
	master_header->fills = NULL;
	master_header->frees = addr + sizeof(t_zonehead);
	master_header->next = NULL;
	prepare_headers(master_header->frees);
	return (addr);
}
