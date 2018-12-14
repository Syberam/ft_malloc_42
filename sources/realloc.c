/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:11:08 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/12/14 17:38:15 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int				find_size(void *ptr, void *head, size_t size)
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
		{
			if (((size_t)((t_zonehead *)head)->end == TINY_ZONE && size <= TINY)
				|| ((size_t)((t_zonehead *)head)->end == SMALL_ZONE && size
					<= SMALL))
			{
				(((t_zonehead *)tmp)->end) = (void *)size;
				return (-1);
			}
			return ((size_t)((t_zonehead *)tmp)->end);
		}
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

static void		*ft_realloc(void *ptr, size_t size)
{
	void	*head;
	void	*tmp;
	size_t	memcpy_size;

	if (ptr == NULL)
		return (ft_malloc(size));
	if (size == 0)
	{
		ft_free(ptr);
		return (NULL);
	}
	if (!(head = ft_find_head(ptr)))
		return (NULL);
	if ((memcpy_size = find_size(ptr, head, size)) == -1)
		return (ptr);
	memcpy_size = (memcpy_size > size) ? size : memcpy_size;
	tmp = ptr;
	ptr = ft_malloc(size);
	ptr = ft_memcpy(ptr, tmp, memcpy_size);
	ft_free(tmp);
	return (ptr);
}

void			*realloc(void *ptr, size_t size)
{
	pthread_mutex_lock(&g_mutex);
	ptr = ft_realloc(ptr, size);
	pthread_mutex_unlock(&g_mutex);
	return (ptr);
}
