/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:21:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/23 19:25:55 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void					*malloc(size_t size)
{
	void				*addr;
	enum e_alloc_size	alloc_kind;
	void				*(*do_alloc[3])(size_t size);

	if ((long)size < 0)
		return (NULL);
	g_masterhead = ft_init_malloc();
	size = ft_align_size(size);
	alloc_kind = ft_find_alloc_size(size);
	do_alloc[0] = ft_give_not_large;
	do_alloc[1] = ft_give_not_large;
	do_alloc[2] = ft_give_large;
	addr = do_alloc[alloc_kind](size);
	return (addr);
}
