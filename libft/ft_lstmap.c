/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 13:31:16 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/15 22:12:58 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *element))
{
	t_list	*start;
	t_list	*link;

	if (!f || !lst)
		return (NULL);
	if (!(link = (t_list *)malloc(sizeof(t_list *))))
		return (NULL);
	link = (*f)(lst);
	start = link;
	lst = lst->next;
	while (lst)
	{
		if (!(link->next = (t_list *)malloc(sizeof(t_list *))))
			return (NULL);
		link->next = (*f)(lst);
		link = link->next;
		lst = lst->next;
	}
	return (start);
}
