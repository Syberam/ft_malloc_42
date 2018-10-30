/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:11:08 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/30 17:18:47 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
/*
static void	ft_move_size_cursor(void *head, void *ptr, size_t size)
{
	void *tmp;

	tmp = ((t_zonehead *)head)->fills;
	while (tmp && ((t_zonehead *)tmp)->fills != ptr)
		tmp = ((t_zonehead *)tmp)->next;
	if (tmp)
		((t_zonehead *)tmp)->end = ((t_zonehead *)tmp)->fills + size;
}
*/
static void		*ft_find_head(void *ptr)
{
	void	*tmp;

	if (ptr == NULL)
		return (NULL);
	tmp = g_masterhead->fills;
	while (tmp)
	{
		if (((t_zonehead *)tmp)->start == ptr)
			return (tmp);
		else if (((t_zonehead *)tmp)->fills != NULL
			&& ptr >= ((t_zonehead *)((t_zonehead *)tmp)->start)->start
			&& ptr <= ((t_zonehead *)((t_zonehead *)tmp)->end)->start)
			return (tmp);
		tmp = ((t_zonehead *)tmp)->next;
	}
	return (tmp);
}

void		*realloc(void *ptr, size_t size)
{
	void	*head;
	void	*tmp;
	size_t	old_size;

	ft_putendl("_____________________________________________________________");
	ft_putendl("REALLOC ci");
	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
		return (ptr);
	head = ft_find_head(ptr);
	if (head)
		old_size = (((t_zonehead *)head)->end - ((t_zonehead *)head)->start);
	if (!head || size > old_size)
	{
		tmp = ptr;
		ptr = malloc(size);
		ptr = ft_memcpy(ptr, tmp, size);
		free(tmp);
	}
	ft_putendl("_____________________________________________________________");
	return (ptr);
}
