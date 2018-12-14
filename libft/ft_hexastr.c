/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexastr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:44:53 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/12/14 13:45:56 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		hexa_power(size_t nb)
{
	size_t			power;

	power = 16;
	while (power < nb / 16)
		power = power * 16;
	return (power);
}

char				*ft_hexastr(void *addr)
{
	size_t			pwr;
	char			*hex;
	int				i;
	size_t			nb;
	char			ret[100];

	hex = "0123456789abcdef";
	nb = (size_t)addr;
	pwr = hexa_power(nb);
	i = 2;
	ret[0] = '0';
	ret[1] = 'x';
	while (pwr > 0)
	{
		ret[i] = hex[nb / pwr];
		nb = nb % pwr;
		pwr = pwr / 16;
		i++;
	}
	ret[i] = 0;
	return (ft_strdup(ret));
}
