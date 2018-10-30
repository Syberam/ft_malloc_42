/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:54:38 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/30 15:32:14 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*ft_extend_zone_header( void )
{
	void	*new_header;

	if ((new_header = mmap(NULL, getpagesize(),
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	g_masterhead->end = new_header + getpagesize();
	return (new_header);
}

void	*ft_init_malloc(void)
{
	t_zonehead	*master_header;

	if (g_masterhead != NULL)
		return (g_masterhead);
	if ((master_header = (t_zonehead *)mmap(NULL, getpagesize(),
			PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0)) ==
			MAP_FAILED)
		return (NULL);
	master_header->start = master_header + sizeof(t_zonehead);
	master_header->fills = NULL;
	master_header->next = master_header->start; 
	master_header->end = master_header + getpagesize();
	return (master_header);
}
