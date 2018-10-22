/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 20:50:10 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/14 17:27:37 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_num(const char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while (str[i] == 48)
		i++;
	while (str[i] > 47 && str[i] < 58)
	{
		i++;
		len++;
	}
	return (len);
}

static int	ft_natoi(const char *str, size_t n)
{
	int		nb;
	size_t	i;

	nb = 0;
	i = 0;
	while (i < n)
	{
		nb = (10 * nb) + (str[i] - 48);
		i++;
	}
	return (nb);
}

static int	ft_atoi_neg(const char *str, size_t i, int nb)
{
	if (ft_len_num(str) > 19)
		return (0);
	else if (ft_len_num(str) > 18)
	{
		if (ft_natoi(str + i, 9) > 922337203 || (ft_natoi(str + i, 9)
			== 922337203 && ft_natoi(str + i + 9, 9) > 685477580) ||
				(ft_natoi(str + i, 9 == 922337203) && ft_natoi(str + i + 9, 9)
				== 685477580 && ft_natoi(str + i + 18, 9) > 7))
			return (0);
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = (10 * nb) - (str[i] - 48);
		i++;
	}
	return (nb);
}

static int	ft_atoi_pos(const char *str, size_t i, int nb)
{
	if (ft_len_num(str) > 19)
		return (-1);
	else if (ft_len_num(str) > 18)
	{
		if (ft_natoi(str + i, 9) > 922337203 || (ft_natoi(str + i, 9)
			== 922337203 && ft_natoi(str + i + 9, 9) > 685477580) ||
				(ft_natoi(str + i, 9 == 922337203) && ft_natoi(str + i + 9, 9)
				== 685477580 && ft_natoi(str + i + 18, 9) > 7))
			return (-1);
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = (10 * nb) + (str[i] - 48);
		i++;
	}
	return (nb);
}

int			ft_atoi(const char *str)
{
	int		nb;
	size_t	i;

	i = 0;
	nb = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == 45 || str[i] == 43)
		i++;
	if (str[i - 1] == 45 && (str[i] > 47 && str[i] < 58))
		return (ft_atoi_neg(str, i, nb));
	else
		return (ft_atoi_pos(str, i, nb));
	return (nb);
}
