/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:35:45 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/15 22:50:35 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] != 0 && s2[i] != 0 && i < n - 1)
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
