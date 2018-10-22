/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 22:10:57 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/13 16:33:27 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	ls1;

	i = 0;
	ls1 = ft_strlen(s1);
	while (i < n && s2[i] != 0)
	{
		s1[ls1 + i] = s2[i];
		i++;
	}
	s1[ls1 + i] = 0;
	return (s1);
}
