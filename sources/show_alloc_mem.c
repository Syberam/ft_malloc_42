/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:48:20 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/12/14 15:45:22 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*
**		line41
**		total += (size_t)((t_zonehead *)heads[i])->end;
**		ft_putnbr((size_t)((t_zonehead *)heads[i--])->end);
**		ft_putstr("/");
***		line42
*/

static size_t	ft_print_blocks(void *zone_head, size_t kind)
{
	size_t		total;
	void		*heads[NB_BLOCKS + 1];
	int			i;

	total = 0;
	i = 0;
	heads[i] = ((t_zonehead *)zone_head)->fills;
	while (heads[i] && ((t_zonehead *)heads[i++])->fills)
		heads[i] = ((t_zonehead *)heads[i - 1])->fills;
	i--;
	while (i >= 0)
	{
		ft_print_hexa(((t_zonehead *)heads[i])->start);
		ft_putstr(" - ");
		ft_print_hexa(((t_zonehead *)heads[i])->start +
			(size_t)((t_zonehead *)heads[i])->end);
		ft_putstr(" : ");
		ft_putnbr(kind);
		ft_putendl(" octets");
		i--;
	}
	return (total);
}

static size_t	show_tinies(void)
{
	size_t	total;
	void	*master_head;

	total = 0;
	master_head = g_masterhead->fills;
	while (master_head)
	{
		if (((t_zonehead *)master_head)->fills &&
			(size_t)(((t_zonehead *)master_head)->end) == TINY_ZONE)
		{
			ft_putstr(" TINY ");
			ft_print_hexa(((t_zonehead *)
			((t_zonehead *)master_head)->start)->start);
			ft_putendl(" :");
			total += ft_print_blocks(master_head, TINY);
		}
		master_head = ((t_zonehead *)master_head)->next;
	}
	return (total);
}

static size_t	show_smalls(void)
{
	size_t		total;
	void		*master_head;

	total = 0;
	master_head = g_masterhead->fills;
	while (master_head)
	{
		if (((t_zonehead *)master_head)->fills &&
			(size_t)(((t_zonehead *)master_head)->end) == SMALL_ZONE)
		{
			ft_putstr(" SMALL ");
			ft_print_hexa(((t_zonehead *)
			((t_zonehead *)master_head)->start)->start);
			ft_putendl(" :");
			total += ft_print_blocks(master_head, SMALL);
		}
		master_head = ((t_zonehead *)master_head)->next;
	}
	return (total);
}

static size_t	show_larges(void)
{
	size_t	total;
	void	*master_head;

	master_head = g_masterhead->fills;
	ft_putendl(" LARGE :");
	total = show_larges_mem(master_head);
	return (total);
}

void			show_alloc_mem(void)
{
	size_t		total;

	pthread_mutex_lock(&g_mutex);
	total = show_tinies() + show_smalls() + show_larges();
	ft_putstr("Total : ");
	ft_putnbr(total);
	ft_putendl(" octets");
	pthread_mutex_unlock(&g_mutex);
}
