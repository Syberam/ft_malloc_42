/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:24:43 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/08 20:10:42 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
	{
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		if (n > -10)
			ft_putchar_fd(45, fd);
		ft_putchar_fd((48 - (n % 10)), fd);
	}
	else if (n > 0)
	{
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd((n % 10) + 48, fd);
	}
	if (n == 0)
		ft_putchar_fd(48, fd);
}
