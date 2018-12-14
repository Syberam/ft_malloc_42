/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 11:48:20 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/12/14 15:40:26 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t			show_larges_mem(void *master_head)
{
	size_t	size;
	size_t	total;

	total = 0;
	if (master_head)
	{
		total += show_larges_mem(((t_zonehead *)master_head)->next);
		if (!((t_zonehead *)master_head)->fills)
		{
			ft_print_hexa(((t_zonehead *)master_head)->start);
			ft_putstr(" - ");
			ft_print_hexa(((t_zonehead *)master_head)->end);
			size = ((t_zonehead *)master_head)->end
				- ((t_zonehead *)master_head)->start;
			total += size;
			ft_putstr(" : ");
			ft_putnbr(size);
			ft_putendl(" octets");
		}
		master_head = ((t_zonehead *)master_head)->next;
	}
	return (total);
}
