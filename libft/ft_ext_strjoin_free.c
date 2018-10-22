/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ext_strjoin_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 18:06:08 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/24 19:37:03 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen_pr(char const *s)
{
	if (!s)
		return (0);
	return (ft_strlen(s));
}

static void		ft_free_join(char const *s1, char const *s2, size_t mal)
{
	if (mal == 1 || mal == 3)
		free((void **)s1);
	if (mal == 2 || mal == 3)
		free((void **)s2);
}

static char		*ft_monojoin(char const *s1, char const *s2, size_t mal)
{
	char		*sj;

	if (!s2 && !s1)
		return (NULL);
	else if (!s1 && (mal == 1 || mal == 3))
		return (NULL);
	else if (!s2 && (mal == 2 || mal == 3))
		return (NULL);
	else if (!s1)
	{
		sj = strdup(s2);
		ft_free_join(s1, s2, mal);
		return (sj);
	}
	else if (!s2)
	{
		sj = strdup(s1);
		ft_free_join(s1, s2, mal);
		return (sj);
	}
	return (NULL);
}

char			*ft_ext_strjoin_free(char const *s1,
					char const *s2, size_t mal)
{
	char		*sj;
	size_t		i;
	size_t		ls1;

	if (!s2 || !s1)
		return (ft_monojoin(s1, s2, mal));
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
	ft_free_join(s1, s2, mal);
	sj[i] = 0;
	return (sj);
}
