/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:11:08 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/11/07 18:01:03 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
/*
static void		ft_move_size_cursor(void *head, void *ptr, size_t size)
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
	size_t	dist;

	if (ptr == NULL)
		return (NULL);
//	ft_putendl(" ___ find head 1 ___ ");
	tmp = g_masterhead->fills;
//	ft_putendl(" ___ find head 2 ___ ");
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
//			ft_print_hexa_endl(tmp);
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
//	size_t	old_size;

/*	ft_putstr(" ___ REALLOC in ___ ");
	ft_print_hexa_endl(ptr);
*/	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
//	ft_putendl(" ___ REALLOC 1 ___ ");
	if (!(head = ft_find_head(ptr)))
		return NULL;
//	ft_print_hexa_endl(head);
//	ft_putendl(" ___ REALLOC 2 ___ ");
/*	if (head)
		old_size = (((t_zonehead *)head)->end - ((t_zonehead *)head)->start);
	else
		return (ptr);
	ft_putstr("old size : ");
	ft_putnbr(old_size);
	ft_putstr(" new size : ");
	ft_putnbr(size);
	ft_putendl("");
	ft_putendl(" ___ REALLOC 3 ___ ");
	if (!head || size > old_size)
	{
*/		tmp = ptr;
		ptr = malloc(size);
		ptr = ft_memcpy(ptr, tmp, size);
		free(tmp);
/*	}
	ft_putendl(" ___ REALLOC out ___ ");
*/	return (ptr);
}
