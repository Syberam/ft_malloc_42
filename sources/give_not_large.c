/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_not_large.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:03:16 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/24 12:27:49 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*ft_give_map(void *zone, enum e_alloc_size kind)
{
	size_t	alloc_size;
	size_t	block_size;
	size_t	i;
	void	*tmp;
	void	*addr;

	alloc_size = (kind == IS_TINY) ? TINY_ZONE : SMALL_ZONE;
	block_size = (kind == IS_TINY) ? TINY : SMALL;
	if((addr = mmap(NULL, alloc_size,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	tmp = ((t_zonehead *)zone)->frees;
	i = 0;
	while (((t_zonehead *)tmp))
	{
		((t_zonehead *)tmp)->frees = addr + i;
		tmp = ((t_zonehead *)tmp)->next;
		i += block_size;
	}
	return (zone);
}

static void	*ft_give_new_zone(enum e_alloc_size kind)
{
	void	*zone;

	if (g_masterhead->frees == NULL)
		if (!(g_masterhead->frees = ft_extend_allocs(getpagesize())))
			return (NULL);
	zone = g_masterhead->frees;
	g_masterhead->frees = ((t_zonehead *)zone)->next;
	((t_zonehead *)zone)->next = g_masterhead->fills;
	g_masterhead->fills = zone;
	((t_zonehead *)zone)->kind = kind;
	((t_zonehead *)zone)->frees = ft_extend_allocs(NB_BLOCKS
		* sizeof(t_zonehead));
	return (zone);
}

static void	*ft_give_free_link(void *zone, enum e_alloc_size kind)
{
	void	*addr;

	if (((t_zonehead *)zone)->frees == NULL)
		if (!(zone = ft_give_map(zone, kind)))
			return (NULL);
	addr = ((t_zonehead *)zone)->frees;
	if (addr)
	{
		((t_zonehead *)zone)->frees = ((t_zonehead *)addr)->next;
		((t_zonehead *)addr)->next = ((t_zonehead *)zone)->fills;
		((t_zonehead *)zone)->fills = addr;
	}
	return (addr);
}

static void	*ft_find_free_zone(enum e_alloc_size kind)
{
	void	*head;

	head = g_masterhead->fills;
	while (head)
	{
		if (((t_zonehead *)head)->kind == kind && ((t_zonehead *)head)->frees)
			return (head);
		head = ((t_zonehead *)head)->next;
	}
	if (head == NULL)
		head = ft_give_new_zone(kind);
	return (head);
}

void	*ft_give_not_large(size_t size)
{
	void	*addr;
	enum e_alloc_size kind;

	kind = (size < SMALL) ? IS_TINY : IS_SMALL;
	addr = ft_find_free_zone(kind);
	addr = ft_give_free_link(addr, kind);
	if (addr)
	{
		((t_zonehead *)addr)->fills = ((t_zonehead *)addr)->frees;
		((t_zonehead *)addr)->frees = ((t_zonehead *)addr)->fills + size;
	}
	return (addr);
}
