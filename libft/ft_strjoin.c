/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:00:56 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/16 11:52:11 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_pr(char const *s)
{
	if (!s)
		return (0);
	return (ft_strlen(s));
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	char		*sj;
	size_t		i;
	size_t		ls1;

	if (!s2 || !s1)
		return (NULL);
	i = 0;
	ls1 = ft_strlen_pr(s1);
	if (!(sj = (char *)malloc(sizeof(char) * (ls1 + ft_strlen_pr(s2) + 1))))
		return (0);
	while (i < ls1)
	{
		sj[i] = s1[i];
		i++;
	}
	while (s2[i - ls1] != 0)
	{
		sj[i] = s2[i - ls1];
		i++;
	}
	sj[i] = 0;
	return (sj);
}
