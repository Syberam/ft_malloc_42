/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 20:24:11 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/15 22:11:28 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*this;

	if (!alst)
		return ;
	this = *alst;
	while (this)
	{
		(*del)(this->content, this->content_size);
		free(this);
		this = this->next;
	}
	*alst = NULL;
}
