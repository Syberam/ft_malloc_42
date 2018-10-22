/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:02:54 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/14 19:59:41 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!(str = (void *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (i < size + 1)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
