/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 17:14:53 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/02 21:52:57 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = 0;
	while (src[i] != 0 && (len - i) != 0)
	{
		dst[i] = src[i];
		i++;
	}
	while (len - i > 0)
	{
		dst[i] = 0;
		i++;
	}
	return (dst);
}
