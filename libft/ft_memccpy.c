/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 10:27:05 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/01 12:49:11 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*cd;
	const char	*cs;
	size_t		cnt;

	cd = dst;
	cs = src;
	cnt = 0;
	while (cnt < n)
	{
		*(cd + cnt) = *(cs + cnt);
		if (*(cs + cnt) == c)
			return (dst + cnt + 1);
		cnt++;
	}
	return (NULL);
}
