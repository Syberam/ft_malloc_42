/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:11:08 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/23 19:37:44 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

static void	ft_move_size_cursor(void *head, void *ptr, size_t size)
{
	void *tmp;

	tmp = ((t_zonehead *)head)->fills;
	while (tmp && ((t_zonehead *)tmp)->fills != ptr)
		tmp = ((t_zonehead *)tmp)->next;
	if (tmp)
		((t_zonehead *)tmp)->frees = ((t_zonehead *)tmp)->fills + size;
}

void		*ft_find_head(void *ptr)
{
	void	*tmp;
	int		kinds[3];

	kinds[0] = TINY_ZONE;
	kinds[1] = SMALL_ZONE;
	kinds[2] = SMALL_ZONE + 16;
	if (ptr == NULL)
		return (NULL);
	tmp = g_masterhead->fills;
	while (tmp && (ptr < tmp || ptr > tmp + kinds[((t_zonehead *)tmp)->kind]))
		tmp = ((t_zonehead *)tmp)->next;
	return (tmp);
}

void		*realloc(void *ptr, size_t size)
{
	void	*head_ref;
	void	*tmp;

	if (ptr == NULL)
		return (malloc(size));
	size = ft_align_size(size);
	head_ref = ft_find_head(ptr);
	if (((t_zonehead *)head_ref)->kind == IS_TINY && size <= TINY)
		ft_move_size_cursor(head_ref, ptr, size);
	else if (((t_zonehead *)head_ref)->kind == IS_SMALL && size > TINY_ZONE
		&& size <= SMALL)
		ft_move_size_cursor(head_ref, ptr, size);
	else
	{
		tmp = ptr;
		ptr = malloc(size);
		ptr = ft_memcpy(ptr, tmp, size);
		free(tmp);
	}
	return (ptr);
}
