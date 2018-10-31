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
/*
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
*/
static void		ft_free_large(void	*head, void *prev_head)
{
	size_t	size;

	ft_putendl("_____ FREE LARGE IN _________________________________________");
		ft_putstr(" ptr to free : ");
		ft_print_hexa(((t_zonehead *)head)->start);
		ft_putendl("");
		ft_print_hexa(head);
		ft_putendl("");
		ft_putstr(" head->next : ");
		ft_print_hexa(((t_zonehead *)head)->next);
		ft_putendl("");
		ft_print_hexa(prev_head);
		ft_putendl("");
	if (head == NULL)
		return ;
	size = ((t_zonehead *)head)->end - ((t_zonehead *)head)->start;
	munmap(((t_zonehead *)head)->start, size);
	if (prev_head == NULL)
		g_masterhead->fills = ((t_zonehead *)head)->next;
	else
		((t_zonehead *)prev_head)->next = ((t_zonehead *)head)->next;
		ft_putendl("");
		ft_putendl("");
		ft_print_hexa(((t_zonehead *)prev_head)->next);
		ft_putendl("");
		ft_print_hexa(g_masterhead->fills);
		ft_putendl("");
		ft_print_hexa(prev_head);
		ft_putendl("");
	((t_zonehead *)head)->next = g_masterhead->next;
	g_masterhead->next = head;
	((t_zonehead *)head)->start = NULL;
	((t_zonehead *)head)->end = NULL;
	ft_putendl("_____ FREE LARGE OUT ________________________________________");
}

void		free(void *ptr)
{
	void	*tmp_prev;
	void	*tmp;

	ft_putstr("_____ FREE IN ____________________________");
	ft_print_hexa(ptr);
	ft_putendl("_____");
	if (ptr == NULL)
		return ;
	tmp = g_masterhead->fills;
	tmp_prev = NULL;
		ft_putstr("__ tmp      : ");
		ft_print_hexa(tmp);
		ft_putendl("");
		ft_putstr("__ tmp next : ");
		ft_print_hexa(((t_zonehead *)tmp)->next);
		ft_putendl("");
		if (((t_zonehead *)tmp)->next)
		{
			ft_print_hexa(((t_zonehead *)((t_zonehead *)tmp)->next)->next);
			ft_putendl("");
		}
	while (tmp)
	{
//		ft_putendl("_____ FREE LOOP _________________________________________");
		if (((t_zonehead *)tmp)->start == ptr)
			ft_free_large(tmp, tmp_prev);
	/*	else if (((t_zonehead *)tmp)->fills != NULL
				&& ptr >= ((t_zonehead *)((t_zonehead *)tmp)->start)->start
				&& ptr <= ((t_zonehead *)tmp)->end)
			ft_free_not_large(tmp, ptr);
	*/	tmp_prev = tmp;
		tmp = ((t_zonehead *)tmp)->next;
	}
	ft_putendl("_____ FREE OUT ______________________________________________");
}
