/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:21:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/11/07 17:18:09 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t					g_nb_tiny;
size_t					g_nb_small;
size_t					g_nb_large;

void					*malloc(size_t size)
{
	void				*addr;
	enum e_alloc_size	kind;
	void				*(*do_alloc[3])(size_t size);

	if ((long)size < 0)
		return (NULL);
	g_masterhead = ft_init_malloc();
//	ft_putnbr(size);
	size = ft_align_size(size);
	kind = ft_find_alloc_size(size);
	do_alloc[0] = ft_give_not_large;
	do_alloc[1] = ft_give_not_large;
	do_alloc[2] = ft_give_large;
	addr = do_alloc[kind](size);
/*	ft_putstr(" : ");
	if (kind == 0)
		ft_putstr("[TINY]");
	else if (kind == 1)
		ft_putstr("[SMALL]");
	else
		ft_putstr("[LARGE]");
	ft_putstr(" new size : ");
	ft_putnbr(size);
	ft_putstr(" : ");
	ft_putstr(" _addr : ");
	ft_print_hexa_endl(addr);
*/	return (addr);
}
