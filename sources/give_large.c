/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 16:02:56 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/24 19:43:41 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*ft_give_large(size_t size)
{
	void	*addr;
	void	*current;

	if (((t_zonehead *)g_masterhead->next)->frees == NULL)
		if (!(g_masterhead->frees = ft_extend_allocs(getpagesize())))
			return (NULL);
	if ((addr = mmap(NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	current = ((t_zonehead *)g_masterhead->next)->frees;
	((t_zonehead *)current)->fills = addr;
	((t_zonehead *)current)->kind = IS_LARGE;
	((t_zonehead *)current)->frees = addr + size;
	if (current + sizeof(t_zonehead) >=
			((t_zonehead *)g_masterhead->next)->next)
		((t_zonehead *)g_masterhead->next)->frees = NULL;
	else
		((t_zonehead *)g_masterhead->next)->frees = current
			+ sizeof(t_zonehead);
	((t_zonehead *)current)->next = g_masterhead->fills;
	g_masterhead->fills = current;
	return (addr);
}

/*
 *
 *
 *    [ ENERAL META ]
 *        [ kind  = IS_MASTER ]
 *        [ frees = TINYs     ]
 *        [ fills = SMALLs    ]
 *        [ next  = LARGEs    ]
 *         |
 *          ->[ kind  = IS_LARGE            ]
 *            [ frees = start of free HZone ]__________
 *            [ fills = last large header   ]___       |
 *            [ next  = end of headerZone   ]   |      |
 *             /                                V      V
 *            |   [    LH0   ][    LH1   ][    LH2   ] [0000000000000000000000]
 * kind  :    |                                                              ^
 * frees :    |      map begin     ``           ``                           |
 * fills :    |      map end       ``           ``                           |
 * next  :    |        NULL  <-    LH0   <-    LH1                           |
 *            |______________________________________________________________|
 *
 */
