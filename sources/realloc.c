/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 14:11:08 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/26 11:27:22 by sbonnefo         ###   ########.fr       */
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

	if (ptr == NULL)
		return (malloc(size));
	if (size == 0)
		return (malloc(size));
//	ft_putendl("ICI0");
	head = ft_find_head(ptr);
/*	if (!(head = ft_find_head(ptr)))
		return (ptr);
	ft_putendl("ICI1");
	size_t	deduc_size;
	ft_putendl("ICI2");
	deduc_size = (size_t)(((t_zonehead *)head)->end -
			((t_zonehead *)head)->start);
	ft_putendl("ICI3");
	ft_putnbr(deduc_size);
	ft_putendl("");
	ft_putendl("ICI4");
*///	printf("alloc size %lu",(((t_zonehead *)head)->end - ((t_zonehead *)head)->start));
	/*	if (((t_zonehead *)head_ref)->fills == NULL)
	{
*/
	if (!head || size > (size_t)(((t_zonehead *)head)->end
				- ((t_zonehead *)head)->start))
	{
		tmp = ptr;
		ptr = malloc(size);
		ptr = ft_memcpy(ptr, tmp, size);
		free(tmp);
	}
/*	}
*/
	/* if size <= get old block size ->move cursor;
	*/

	return (ptr);
}
