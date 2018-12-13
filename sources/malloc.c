/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:21:47 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/12/13 16:58:25 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

pthread_mutex_t g_mutex = PTHREAD_MUTEX_INITIALIZER;

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
	pthread_mutex_lock(&g_mutex);
	g_masterhead = ft_init_malloc();
	size = ft_align_size(size);
	kind = ft_find_alloc_size(size);
	do_alloc[0] = ft_give_not_large;
	do_alloc[1] = ft_give_not_large;
	do_alloc[2] = ft_give_large;
	addr = do_alloc[kind](size);
	pthread_mutex_unlock(&g_mutex);
	return (addr);
}
