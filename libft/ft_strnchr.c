/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 17:59:44 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/15 17:59:46 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int n)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)s;
	if (c == 0)
		return (str + ft_strlen(str));
	while (s[i] != 0 && i < n - 1)
	{
		if (s[i] == c)
			return (str + i);
		i++;
	}
	return (NULL);
}
