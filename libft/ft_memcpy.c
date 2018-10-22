/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:43:48 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/01 10:55:26 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*cd;
	const char	*cs;

	cd = dst;
	cs = src;
	while (n > 0)
	{
		*(cd + n - 1) = *(cs + n - 1);
		n--;
	}
	return (dst);
}
