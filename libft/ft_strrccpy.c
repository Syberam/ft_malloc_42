/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrccpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:58:51 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/25 18:08:54 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrccpy(char *dst, const char *src, int c)
{
	int		i;

	i = ft_strlen(src) + 1;
	while (src[i] != c && i > 0)
		i--;
	if (i == 0)
		return ((char *)src);
	else
	{
		dst = ft_strncpy(dst, src, i);
		dst[i] = 0;
	}
	return (dst);
}
