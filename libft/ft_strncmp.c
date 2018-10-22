/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:31:36 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/14 16:03:03 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n <= 0)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && i < n - 1 && (s1[i] != 0 || s2[i] != 0))
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
