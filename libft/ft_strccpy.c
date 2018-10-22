/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 17:17:07 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/25 19:28:47 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strccpy(char *dst, const char *src, int c)
{
	int		i;

	i = 0;
	while (src[i] != 0 && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dst);
}
