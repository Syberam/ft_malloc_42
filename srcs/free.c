/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 17:52:55 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/22 18:58:06 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	free(void *ptr)
{
	void	*tmp;
	int		kinds[2];

	kinds[0] = TINY_ZONE;
	kinds[1] = SMALL_ZONE;

	if (ptr == NULL)
		return ;
	while (tmp)
	{
		if (((t_zonehead *)tmp)->kind == IS_LARGE
				&& ((t_zonehead *)tmp)->fills == ptr)
			return ft_free_large();
		if (ptr >= tmp
			&& ptr <= tmp + kinds[((t_zonehead *)tmp)->kind])
			break;
		tmp = ((t_zonehead *)tmp)->next;
	}
}
