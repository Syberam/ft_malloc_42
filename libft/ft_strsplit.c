/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:34:09 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/15 22:59:11 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_nw(char const *s, char c)
{
	size_t			i;
	size_t			w;

	i = 0;
	w = 0;
	if (!c)
		return (1);
	while (s[i] != 0)
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i] != 0)
			w++;
		while (s[i] != c && s[i] != 0)
			i++;
		while (s[i] == c)
			i++;
	}
	return (w);
}

static size_t		ft_lw(char const *s, unsigned int i, char c)
{
	size_t			len;

	len = 0;
	while (s[i] != c && s[i] != 0)
	{
		len++;
		i++;
	}
	return (len);
}

char				**ft_strsplit(char const *s, char c)
{
	char			**tab;
	size_t			it;
	unsigned int	i;

	it = 0;
	i = 0;
	if (!s)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * ft_nw(s, c) + 1)))
		return (NULL);
	while (it < ft_nw(s, c))
	{
		while (s[i] == c)
			i++;
		tab[it] = ft_strsub(s, i, ft_lw(s, i, c));
		while (s[i] != c && s[i] != 0)
			i++;
		it++;
	}
	tab[it] = 0;
	return (tab);
}
