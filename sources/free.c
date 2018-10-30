/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:52:55 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/30 17:16:30 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		ft_free_not_large(void	*head, void *link)
{
	void	*block_head;
	void	*prev_block_head;

	block_head = ((t_zonehead *)head)->fills;
	prev_block_head = block_head;
	while (block_head && ((t_zonehead *)block_head)->start != link)
	{
		prev_block_head = block_head;
		block_head = ((t_zonehead *)block_head)->fills;
	}
	if (block_head == NULL)
		return ;
	if (prev_block_head == NULL)
		((t_zonehead *)head)->fills = ((t_zonehead *)block_head)->fills;
	else
		((t_zonehead *)prev_block_head)->fills =
			((t_zonehead *)block_head)->fills;
	((t_zonehead *)block_head)->end = ((t_zonehead *)block_head)->start;
	((t_zonehead *)block_head)->next = 
		((t_zonehead *)((t_zonehead *)head)->fills)->next;
	((t_zonehead *)((t_zonehead *)head)->fills)->next = block_head;
}

static void		ft_free_large(void	*head, void *prev_head)
{
	size_t	size;

	if (head == NULL)
		return ;
	size = ((t_zonehead *)head)->end - ((t_zonehead *)head)->start;
	munmap(((t_zonehead *)head)->start, size);
	if (prev_head == NULL)
		g_masterhead->fills = ((t_zonehead *)head)->next;
	else
		((t_zonehead *)prev_head)->next = ((t_zonehead *)head)->next;
	((t_zonehead *)head)->next = g_masterhead->next;
	g_masterhead->next = head;
	((t_zonehead *)head)->start = NULL;
	((t_zonehead *)head)->fills = NULL;
	((t_zonehead *)head)->end = NULL;
}

void		free(void *ptr)
{
	void	*tmp_prev;
	void	*tmp;

	ft_putendl("_____________________________________________________________");
	ft_putendl("FREEEci");
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
				&& ptr <= ((t_zonehead *)tmp)->end)
			ft_free_not_large(tmp, ptr);
		tmp_prev = tmp;
		tmp = ((t_zonehead *)tmp)->next;
	}
	ft_putendl("_____________________________________________________________");
}
