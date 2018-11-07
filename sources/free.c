/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:52:55 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/11/07 17:15:42 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void		ft_free_not_large(void *head, void *link)
{
	void	*block_head;
	void	*prev_block_head;
	void	*free_heads;

//	ft_putendl("                                    free not large in : ");
	block_head = ((t_zonehead *)head)->fills;
	prev_block_head = NULL;
	if (block_head)
		free_heads = ((t_zonehead *)block_head)->next;
	while (block_head && ((t_zonehead *)block_head)->start != link)
	{
/*		ft_putstr(" ici ");
		ft_print_hexa(block_head);
		ft_putstr(" start : ");
		ft_print_hexa(((t_zonehead *)block_head)->start);
		ft_putstr(" vs : ");
		ft_print_hexa_endl(link);
*/		prev_block_head = block_head;
		block_head = ((t_zonehead *)block_head)->fills;
	}
//	ft_putendl("                                    free large here : ");
	if (block_head == NULL)
		return ;
	if (prev_block_head == NULL)
		((t_zonehead *)head)->fills = ((t_zonehead *)block_head)->fills;
	else
		((t_zonehead *)prev_block_head)->fills =
			((t_zonehead *)block_head)->fills;
	((t_zonehead *)block_head)->end = 0;
	((t_zonehead *)block_head)->next = free_heads;
	if (((t_zonehead *)head)->fills)
		((t_zonehead *)((t_zonehead *)head)->fills)->next = block_head;
//	ft_putendl("                                    free not large out : ");
}

static void		ft_free_large(void *head, void *prev_head)
{
	size_t	size;

//	ft_putendl("                                    free large in : ");
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
	((t_zonehead *)head)->end = NULL;
//	ft_putendl("                                    free large in : ");
}

void			free(void *ptr)
{
	void	*tmp_prev;
	void	*tmp;
	void	*start;
	void	*end;

/*	ft_putstr("                                    free : ");
	ft_print_hexa_endl(ptr);
*/	if (ptr == NULL)
		return ;
	tmp = g_masterhead->fills;
	tmp_prev = NULL;
	while (tmp)
	{
		if (((t_zonehead *)tmp)->start == ptr)
			return (ft_free_large(tmp, tmp_prev));
		else if (((t_zonehead *)tmp)->fills != NULL)
		{
			start = ((t_zonehead *)((t_zonehead *)tmp)->start)->start;
			end = start + (size_t)((t_zonehead *)tmp)->end;
/*			ft_print_hexa(start);
			ft_putstr(" < ");
			ft_print_hexa(ptr);
			ft_putstr(" < ");
			ft_print_hexa_endl(end);
*/			if (ptr >= start && ptr < end)
				return (ft_free_not_large(tmp, ptr));
		}
		tmp_prev = tmp;
		tmp = ((t_zonehead *)tmp)->next;
	}
}
