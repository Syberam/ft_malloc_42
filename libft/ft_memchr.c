/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:50:45 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/13 18:50:49 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*cs;
	unsigned char	cc;
	size_t			cnt;

	cs = (unsigned char *)s;
	cc = c;
	cnt = 0;
	while (cnt < n)
	{
		if (cs[cnt] == cc)
			return (cs + cnt);
		cnt++;
	}
	return (NULL);
}
