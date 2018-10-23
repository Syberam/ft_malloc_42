/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:01:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/23 15:15:53 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t				ft_align_size(size_t size)
{
	size_t		rest;

	rest = size % 16;
	if (rest != 0 || size == 0)
		size += 16 - rest;
	return (size);
}

enum e_alloc_size	ft_find_alloc_size(size_t size)
{
	if (size <= TINY)
		return (IS_TINY);
	if (size <= SMALL)
		return (IS_SMALL);
	return (IS_LARGE);
}
