/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:09:11 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/06 20:29:37 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	ib;
	size_t	il;
	char	*b;

	b = (char *)big;
	ib = 0;
	while (big[ib] != 0)
	{
		il = 0;
		if (little[il] == 0)
			return (b);
		while (little[il] == big[ib])
		{
			il++;
			ib++;
			if (little[il] == 0 && ib <= len)
				return (b + ib - il);
			else if (big[ib] == 0)
				return (0);
		}
		ib = ib - il + 1;
	}
	return (0);
}
