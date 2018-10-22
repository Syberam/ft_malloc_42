/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:49:29 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/13 16:10:06 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*cd;
	const char	*cs;
	int			i;

	i = 0;
	cs = src;
	cd = dst;
	if (src < dst)
	{
		while (len > 0)
		{
			*(cd + len - 1) = *(cs + len - 1);
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*(cd + i) = *(cs + i);
			len--;
			i++;
		}
	}
	return (dst);
}
