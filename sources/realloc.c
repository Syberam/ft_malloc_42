/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:11:08 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/12/13 17:04:19 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t			find_size(void *ptr, void *head)
{
	void	*tmp;

	if (ptr == NULL)
		return (0);
	if (((t_zonehead *)head)->start == ptr)
		return (((t_zonehead *)head)->end - ((t_zonehead *)head)->start);
	tmp = ((t_zonehead *)head)->fills;
	while (tmp)
	{
		if (((t_zonehead *)tmp)->start == ptr)
			return ((size_t)((t_zonehead *)tmp)->end);
		tmp = ((t_zonehead *)tmp)->fills;
	}
	return (0);
}

static void		*ft_find_head(void *ptr)
{
	void	*tmp;
	size_t	dist;

	if (ptr == NULL)
		return (NULL);
	tmp = g_masterhead->fills;
	while (tmp)
	{
		if (((t_zonehead *)tmp)->start == ptr)
			return (tmp);
		else if (((t_zonehead *)tmp)->fills != NULL
			&& ptr >= ((t_zonehead *)((t_zonehead *)tmp)->start)->start
			&& ptr <= (((t_zonehead *)((t_zonehead *)tmp)->start)->start
			+ (size_t)((t_zonehead *)tmp)->end))
		{
			dist = ptr - ((t_zonehead *)((t_zonehead *)tmp)->start)->start;
			if ((size_t)((t_zonehead *)tmp)->end == TINY_ZONE && dist % TINY)
				return (NULL);
			if ((size_t)((t_zonehead *)tmp)->end == SMALL_ZONE && dist % SMALL)
				return (NULL);
			return (tmp);
		}
		tmp = ((t_zonehead *)tmp)->next;
	}
	return (tmp);
}

void			*realloc(void *ptr, size_t size)
{
	void	*head;
	void	*tmp;
	size_t	memcpy_size;

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (!(head = ft_find_head(ptr)))
		return NULL;
	memcpy_size = find_size(ptr, head);
	memcpy_size = (memcpy_size > size) ? size : memcpy_size;
	tmp = ptr;
	ptr = malloc(size);
	ptr = ft_memcpy(ptr, tmp, memcpy_size);
	free(tmp);
	return (ptr);
}
