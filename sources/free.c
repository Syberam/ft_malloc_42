/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:52:55 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/25 18:57:41 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
/*
static void	ft_free_map(void *to_free, void *prev)
{
	size_t		size;
	void		*to_munmap;

	to_munmap = ((t_zonehead *)to_free)->fills;
	if (((t_zonehead *)to_free)->kind == IS_LARGE)
		size = ((t_zonehead *)to_free)->frees - to_munmap;
	else if (((t_zonehead *)to_free)->kind == IS_TINY)
		size = TINY_ZONE;
	else
		size = SMALL_ZONE;
	if (prev != NULL)
		((t_zonehead *)prev)->next = ((t_zonehead *)to_free)->next;
	else
		g_masterhead->fills = ((t_zonehead *)to_free)->next;
	((t_zonehead *)to_free)->next = g_masterhead->frees;
	g_masterhead->frees = to_free;
	munmap(to_munmap, size);
	((t_zonehead *)to_free)->fills = NULL;
	((t_zonehead *)to_free)->frees = NULL;
	((t_zonehead *)to_free)->kind = NONE;
}

static void	ft_check_free_map(void *empty_map)
{
	void	*tmp_prev;
	void	*tmp;

	tmp = g_masterhead->fills;
	tmp_prev = NULL;
	while (tmp)
	{
		if (tmp != empty_map
				&& ((t_zonehead *)tmp)->fills == NULL
				&& ((t_zonehead *)tmp)->kind == ((t_zonehead *)tmp)->kind)
			ft_free_map(tmp, tmp_prev);
		tmp_prev = tmp;
		tmp = ((t_zonehead *)tmp)->next;
	}
}

static void	ft_free_link(void *ptr, void *where_free, void *prev)
{
	void	*tmp_prev;
	void	*tmp;

	if (((t_zonehead *)where_free)->kind == IS_LARGE)
		ft_free_map(where_free, prev);
	tmp = ((t_zonehead *)where_free)->fills;
	tmp_prev = NULL;
	while (tmp != ptr && tmp)
	{
		tmp_prev = tmp;
		tmp = ((t_zonehead *)tmp)->next;
	}
	if (tmp && tmp_prev)
		((t_zonehead *)tmp_prev)->next = ((t_zonehead *)tmp)->next;
	else if (tmp)
		((t_zonehead *)where_free)->fills = ((t_zonehead *)tmp)->next;
	if (tmp)
	{
		((t_zonehead *)tmp)->next = g_masterhead->frees;
		((t_zonehead *)where_free)->frees = tmp;
		((t_zonehead *)tmp)->fills = NULL;
		((t_zonehead *)tmp)->frees = NULL;
	}
	if (((t_zonehead *)where_free)->fills == NULL)
		ft_check_free_map(where_free);
}
*/
void		ft_free_not_large(void	*header, void *prev_head, void *link)
{
	(void)header;
	(void)prev_head;
	(void)link;
}

void		ft_free_large(void	*header, void *prev_head)
{
	size_t	size;

	if (header == NULL)
		return ;
	size = ((t_zonehead *)header)->end - ((t_zonehead *)header)->start;
	munmap(((t_zonehead *)header)->start, size);
	if (prev_head == NULL)
		g_masterhead->fills = ((t_zonehead *)header)->next;
	else
		((t_zonehead *)prev_head)->next = ((t_zonehead *)header)->next;
	((t_zonehead *)header)->next = g_masterhead->next;
	g_masterhead->next = header;
	((t_zonehead *)header)->start = NULL;
	((t_zonehead *)header)->fills = NULL;
	((t_zonehead *)header)->end = NULL;
}

void		free(void *ptr)
{
	void	*tmp_prev;
	void	*tmp;

	if (ptr == NULL)
		return ;
	tmp = g_masterhead->fills;
	tmp_prev = NULL;
	while (tmp)
	{
		if (((t_zonehead *)tmp)->start == ptr)
			ft_free_large(tmp, tmp_prev);
		else if (((t_zonehead *)tmp)->fills != NULL
			&& ptr >= ((t_zonehead *)((t_zonehead *)tmp)->start)->start
			&& ptr <= ((t_zonehead *)((t_zonehead *)tmp)->end)->start)
			ft_free_not_large(tmp, tmp_prev, ptr);
		tmp_prev = tmp;
		tmp = ((t_zonehead *)tmp)->next;
	}
}
