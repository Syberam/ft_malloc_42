/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 10:27:18 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/30 10:31:16 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void	*calloc(size_t count, size_t size)
{
	void	*addr;

	ft_putendl("___ CALLOC IN _____________________________________________");
	if (!(addr = malloc(count * size)))
		return (NULL);
	ft_bzero(addr, count * size);
	ft_putendl("___ CALLOC out _____________________________________________");
	return (addr);
}
