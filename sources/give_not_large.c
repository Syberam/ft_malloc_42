/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_not_large.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:03:16 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/30 15:54:27 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*ft_give_block(void *block_head,
		enum e_alloc_size kind)
{
	void	*addr;
	size_t	need_size;

	need_size = (kind == IS_TINY) ? (size_t)TINY_ZONE : (size_t)SMALL_ZONE;
	if (((t_zonehead *)block_head)->start == NULL)
	{
		if ((addr = mmap(NULL, need_size,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
		((t_zonehead *)block_head)->start = addr;
		((t_zonehead *)block_head)->end = (void *)need_size;
		return (addr);
	}
	addr = ((t_zonehead *)block_head)->start;
	return (addr);
}

static void	*ft_give_block_header(void *zone_head, enum e_alloc_size kind)
{
	void	*block_head;
	size_t	need_size;

	if (!zone_head)
		return (NULL);
	need_size = (kind == IS_TINY) ? (size_t)TINY_ZONE : (size_t)SMALL_ZONE;
	if (((t_zonehead *)zone_head)->fills == NULL)
		block_head = ((t_zonehead *)zone_head)->start;
	else
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

static void	*ft_fresh_header_zone( void )
{
	void	*heads_map;

	if ((heads_map = mmap(NULL, NB_BLOCKS * sizeof(t_zonehead),
		PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
		MAP_FAILED)
	return (NULL);
	((t_zonehead *)heads_map)->fills = NULL;
	((t_zonehead *)heads_map)->start = NULL;
	((t_zonehead *)heads_map)->end = NULL;
	((t_zonehead *)heads_map)->next = heads_map;
	return (heads_map);
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
		zone_size = (size_t)((t_zonehead *)zone_head)->end;
		if (zone_size == need_size &&
			((t_zonehead *)((t_zonehead *)zone_head)->fills)->next)
			return (zone_head);
		zone_head = ((t_zonehead *)zone_head)->next;
	}
	if (zone_head == NULL)
		zone_head = ft_give_new_header();
	((t_zonehead *)zone_head)->start = ft_fresh_header_zone();
	((t_zonehead *)zone_head)->fills = NULL;
	return (zone_head);
}

void	*ft_give_not_large(size_t size)
{
	void				*zone_head;
	void				*block_head;
	void				*addr;
	enum e_alloc_size	kind;

	kind = (size < SMALL) ? IS_TINY : IS_SMALL;
	if (!(zone_head = ft_find_free_zone_header(kind)))
		return (NULL);
	if (!(block_head = ft_give_block_header(zone_head, kind)))
		return (NULL);
	if (!(addr = ft_give_block(block_head, kind)))
		return (NULL);
	return (addr);
}
