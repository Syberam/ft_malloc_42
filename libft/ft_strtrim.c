/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 19:34:06 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/16 11:51:10 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	st;
	size_t	nd;
	size_t	ls;

	if (!s)
		return (NULL);
	st = 0;
	nd = 0;
	ls = ft_strlen(s) - 1;
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	if (st == ls + 1)
		return (ft_strdup(s + st));
	while (s[ls - nd] == ' ' || s[ls - nd] == '\n' || s[ls - nd] == '\t')
		nd++;
	return (ft_strsub(s, st, ls - st - nd + 1));
}
