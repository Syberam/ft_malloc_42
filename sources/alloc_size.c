/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 10:01:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/11/07 11:42:52 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

size_t				ft_align_size(size_t size)
{
	if (!size || size & 15)
		size += 16;
	size = size >> 4 << 4;
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
