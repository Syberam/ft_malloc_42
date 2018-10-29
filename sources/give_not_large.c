/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_not_large.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:03:16 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/29 10:55:20 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	*ft_give_block(void *zone_head, void *block_head,
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
		((t_zonehead *)zone_head)->end = addr + need_size;
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
	void				*zone_head;
	void				*block_head;
	void				*addr;
	enum e_alloc_size	kind;

	kind = (size < SMALL) ? IS_TINY : IS_SMALL;
	if (!(zone_head = ft_find_free_zone_header(kind)))
		return (NULL);
	if (!(block_head = ft_give_block_header(zone_head, kind)))
		return (NULL);
	if (!(addr = ft_give_block(zone_head, block_head, kind)))
		return (NULL);
	((t_zonehead *)block_head)->end = addr + size;
	return (((t_zonehead *)addr)->start);
}
