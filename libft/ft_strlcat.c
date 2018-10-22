/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 17:38:26 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/14 15:20:15 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		i;
	size_t		ldst;

	i = 0;
	ldst = ft_strlen(dst);
	if (size <= ldst)
		return (size + ft_strlen(src));
	while (i + ldst + 1 < size && src[i] != 0)
	{
		dst[i + ldst] = src[i];
		i++;
	}
	dst[i + ldst] = 0;
	return (ldst + ft_strlen(src));
}
