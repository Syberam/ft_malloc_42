/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:39:16 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/13 16:27:33 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cs1;
	unsigned char	*cs2;
	size_t			cnt;

	cnt = 0;
	cs1 = (unsigned char *)s1;
	cs2 = (unsigned char *)s2;
	while (cnt < n)
	{
		if (cs1[cnt] != cs2[cnt])
			return (cs1[cnt] - cs2[cnt]);
		cnt++;
	}
	return (0);
}
