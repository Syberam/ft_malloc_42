/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_bwd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 22:26:09 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/15 22:37:12 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_bwd(t_list **alst, t_list *new)
{
	t_list	*link;

	if (alst == NULL)
		return ;
	link = *alst;
	if (*alst == NULL)
		*alst = new;
	else
	{
		while (link->next)
			link = link->next;
		link->next = new;
	}
}
