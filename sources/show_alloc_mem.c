/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:48:20 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/11/05 11:48:23 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "malloc.h"

static void	ft_print_blocks(void *zone_head, int kind)
{
	void	*block_head;

	block_head = ((t_zonehead *)zone_head)->fills;
	while (block_head)
	{
		ft_print_hexa(((t_zonehead *)block_head)->start);
		ft_putstr(" - ");
		ft_print_hexa(((t_zonehead *)block_head)->start +
			(size_t)((t_zonehead *)block_head)->end);
		ft_putstr(" : ");
		ft_putnbr((size_t)((t_zonehead *)block_head)->end);
		ft_putstr("/");
		ft_putnbr(kind);
		ft_putendl(" octets");
		block_head = ((t_zonehead *)block_head)->fills;
	}
}

void	show_alloc_mem(void)
{
	void	*master_head;

	master_head = g_masterhead->fills;
	while (master_head)
	{
/*		if ((size_t)(((t_zonehead *)master_head)->end) <= TINY)
		{
*/			ft_putstr(" TINY ");
			ft_print_hexa(((t_zonehead *)
			((t_zonehead *)master_head)->start)->start);
			ft_putendl(" :");
			ft_print_blocks(master_head, TINY);
//		}
		master_head = ((t_zonehead *)master_head)->next;
	}
}
