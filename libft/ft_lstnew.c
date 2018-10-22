/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 18:33:29 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/13 19:50:34 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;

	if (!(link = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (content == NULL)
	{
		link->content = NULL;
		link->content_size = 0;
	}
	else
	{
		if (!(link->content = ft_memalloc(sizeof(*content) * content_size)))
			return (NULL);
		link->content = ft_memcpy(link->content, content, content_size);
		link->content_size = content_size;
	}
	link->next = NULL;
	return (link);
}
