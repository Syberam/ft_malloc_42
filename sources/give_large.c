/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 10:00:56 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/11/05 11:49:04 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void			*ft_give_new_header(void)
{
	void		*new_header;

	new_header = g_masterhead->next;
	if (new_header == NULL || g_masterhead->next == g_masterhead->end)
		if (!(new_header = ft_extend_zone_header()))
			return (NULL);
	if (((t_zonehead *)new_header)->next)
		g_masterhead->next = ((t_zonehead *)new_header)->next;
	else
		g_masterhead->next = new_header + sizeof(t_zonehead);
	((t_zonehead *)new_header)->next = g_masterhead->fills;
	g_masterhead->fills = new_header;
	return (new_header);
}

void			*ft_give_large(size_t size)
{
	void		*header;
	void		*addr;

	if (!(header = ft_give_new_header()))
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
