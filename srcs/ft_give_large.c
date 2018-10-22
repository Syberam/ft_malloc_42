/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_large.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:45:21 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/22 17:57:08 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*ft_give_large(size_t size)
{
	void	*addr;
	void	*current;

	if (g_masterhead->frees == NULL)
		if (!(g_masterhead->frees = ft_extend_allocs()))
			return NULL;
	if (!(addr = mmap(NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)))
		return (NULL);
	current = g_masterhead->frees;
	((t_zonehead *)current)->fills = addr;
	((t_zonehead *)current)->kind = IS_LARGE;
	((t_zonehead *)current)->frees = NULL;
	g_masterhead->frees = ((t_zonehead *)current)->next;
	((t_zonehead *)current)->next = g_masterhead->fills;
	g_masterhead->fills = current;
	return (addr);
}
