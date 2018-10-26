/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:00:56 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/26 10:19:08 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ft_give_header(void)
{
	void		*new_header;

	new_header = g_masterhead->next;
	if (new_header == NULL || g_masterhead->next == g_masterhead->end)
		if (!(new_header = ft_extend_zone_header()))
			return (NULL);
	return (new_header);
}

void		*ft_give_large(size_t size)
{
	void	*header;
	void	*addr;

	if (!(header = ft_give_header()))
		return (NULL);
	if ((addr = mmap(NULL, size,
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	((t_zonehead *)header)->start = addr;
	((t_zonehead *)header)->end = addr + size;
	((t_zonehead *)header)->fills = NULL;
	return (addr);
}
