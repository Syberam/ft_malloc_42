/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:00:56 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/25 17:03:54 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ft_give_header( enum e_alloc_size kind )
{
	t_zonehead	*root_header;
	void		*new_header;

	if (g_masterhead->next == NULL)
		if (!(new_header = ft_extend_zone_header()))
			return (NULL);
	return (new_header);
}

void		*ft_give_large(size_t size)
{
	void	*header;
	void	*addr;

	if (!(header = ft_give_header(IS_LARGE)))
		return (NULL);
	if ((addr = mmap(NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	((t_zonehead *)header)->fills = addr;
	((t_zonehead *)header)->kind = IS_LARGE;
	((t_zonehead *)header)->frees = addr + size;
	return (addr);
}
