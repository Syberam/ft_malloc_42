/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa_endl.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 09:49:07 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/11/07 09:52:47 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

static size_t		hexa_power(size_t nb)
{
	size_t			power;

	power = 16;
	while (power < nb / 16)
		power = power * 16;
	return (power);
}

void				ft_print_hexa_endl(void *addr)
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
	ft_putendl(ret);
}
