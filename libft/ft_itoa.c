/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 21:05:56 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/08 22:24:34 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*a;
	size_t	l_n;
	size_t	i;

	i = 0;
	l_n = ft_ilen(n);
	if (!(a = (char *)malloc(sizeof(char) * (l_n + 1))))
		return (0);
	if (n < 0)
	{
		a[i] = '-';
		i++;
		while (i < l_n)
		{
			a[i] = 10 - (n / ft_power(10, l_n - i - 1) % 10) + 38;
			i++;
		}
	}
	while (i < l_n)
	{
		a[i] = ((n / ft_power(10, l_n - i - 1)) % 10) + 48;
		i++;
	}
	a[i] = 0;
	return (a);
}
