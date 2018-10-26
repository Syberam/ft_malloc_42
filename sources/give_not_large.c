/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_not_large.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:03:16 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/26 16:27:04 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
/*
static void	*ft_give_map(void *zone, enum e_alloc_size kind)
{
	kind = 0;
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
	kind = 0;

	if (g_masterhead->frees == NULL)
		if (!(g_masterhead->frees = ft_extend_allocs(getpagesize())))
			return (NULL);
	zone = g_masterhead->next;
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
	kind = 0;

	if (((t_zonehead *)zone)->frees == NULL)
		if (!(zone = ft_give_map(zone, kind)))
			return (NULL);
	addr = ((t_zonehead *)zone)->next;
	
	if (addr)
	{
		((t_zonehead *)zone)->frees = ((t_zonehead *)addr)->next;
		((t_zonehead *)addr)->next = ((t_zonehead *)zone)->fills;
		((t_zonehead *)zone)->fills = addr;
	}
	return (addr);
}
*/

static void	*ft_give_block_header(void *zone_head, enum e_alloc_size kind)
{
	void	*block_head;
	size_t	need_size;

	if (!zone_head)
		return (NULL);
	need_size = (kind == IS_TINY) ? (size_t)TINY_ZONE : (size_t)SMALL_ZONE;
	block_head = ((t_zonehead *)((t_zonehead *)zone_head)->fills)->next;
	((t_zonehead *)block_head)->fills = ((t_zonehead *)zone_head)->fills;
	((t_zonehead *)zone_head)->fills = block_head;
	if (!((t_zonehead *)block_head)->next)
		((t_zonehead *)block_head)->next = block_head + sizeof(t_zonehead);
	if (((t_zonehead *)block_head)->next == ((t_zonehead *)zone_head)->start +
		need_size)
		((t_zonehead *)block_head)->next = NULL;
	return (block_head);
}

static void	*ft_find_free_zone_header(enum e_alloc_size kind)
{
	void	*zone_head;
	size_t	need_size;
	size_t	zone_size;

	need_size = (kind == IS_TINY) ? (size_t)TINY_ZONE : (size_t)SMALL_ZONE;
	zone_head = g_masterhead->fills;
	while (zone_head)
	{
		zone_size = (!((t_zonehead *)zone_head)->fills) ? 0 :
			((t_zonehead *)zone_head)->end -
			((t_zonehead *)((t_zonehead *)zone_head)->start)->start;
		if (zone_size == need_size &&
			((t_zonehead *)((t_zonehead *)zone_head)->fills)->next)
			return (zone_head);
		zone_head = ((t_zonehead *)zone_head)->next;
	}
	if (zone_head == NULL)
		zone_head = ft_give_new_header();
	return (zone_head);
}

void	*ft_give_not_large(size_t size)
{
	void				*addr;
	enum e_alloc_size	kind;

	kind = (size < SMALL) ? IS_TINY : IS_SMALL;
	if (!(addr = ft_find_free_zone_header(kind)))
		return (NULL);
	if (!(addr = ft_give_block_header(addr, kind)))
		return (NULL);

/*	addr = ft_give_free_link(addr, kind);
	if (addr)
	{
		((t_zonehead *)addr)->fills = ((t_zonehead *)addr)->frees;
		((t_zonehead *)addr)->frees = ((t_zonehead *)addr)->fills + size;
	}
*/	return (addr);
}
