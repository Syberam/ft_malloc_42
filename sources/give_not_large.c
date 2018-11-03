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

static void	*ft_give_block(void *block_head, size_t size)
{
	void	*addr;

	addr = ((t_zonehead *)block_head)->start;
	((t_zonehead *)block_head)->end = (void *)size;
	
	return (addr);
}

static void	*ft_give_block_header(void *zone_head, size_t need_size)
{
	void	*block_head;
	size_t	block_size;

	if (!zone_head)
		return (NULL);
	block_size = (need_size == TINY_ZONE) ? TINY : SMALL;
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
	if (((t_zonehead *)block_head)->next)
		((t_zonehead *)((t_zonehead *)block_head)->next)->start =
		((t_zonehead *)block_head)->start + block_size;
	return (block_head);
}

static void	*ft_fresh_header_zone(size_t need_size)
{
	void	*heads_map;

	if ((heads_map = mmap(NULL, NB_BLOCKS * sizeof(t_zonehead),
		PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
		MAP_FAILED)
	return (NULL);
	((t_zonehead *)heads_map)->fills = NULL;
	if ((((t_zonehead *)heads_map)->start = mmap(NULL, need_size,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	((t_zonehead *)heads_map)->end = NULL;
	((t_zonehead *)heads_map)->next = NULL;
	return (heads_map);
}

static void	*ft_find_free_zone_header(size_t need_size)
{
	void	*zone_head;
	size_t	zone_size;

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
	{
		zone_head = ft_give_new_header();
		((t_zonehead *)zone_head)->start = ft_fresh_header_zone(need_size);
		((t_zonehead *)zone_head)->fills = NULL;
		((t_zonehead *)zone_head)->end = (void *)need_size;
	}
	return (zone_head);
}

void	*ft_give_not_large(size_t size)
{
	void				*zone_head;
	void				*block_head;
	void				*addr;
	size_t				need_size;

	need_size = (size < SMALL) ? TINY_ZONE : SMALL_ZONE;
	if (!(zone_head = ft_find_free_zone_header(need_size)))
		return (NULL);
	if (!(block_head = ft_give_block_header(zone_head, need_size)))
		return (NULL);
	if (!(addr = ft_give_block(block_head, size)))
		return (NULL);
	ft_putstr(" _____ give not large : ");
	ft_print_hexa(addr);
	return (addr);
}
