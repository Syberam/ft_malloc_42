/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 09:09:48 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/12/14 11:46:30 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*calloc(size_t count, size_t size)
{
	void	*addr;

	if (!(addr = malloc(count * size)))
		return (NULL);
	ft_bzero(addr, count * size);
	return (addr);
}
