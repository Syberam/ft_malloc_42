/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 16:57:02 by sbonnefo          #+#    #+#             */
/*   Updated: 2016/12/14 20:04:29 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		ib;
	int		il;
	char	*b;

	b = (char *)big;
	ib = 0;
	if (big[ib] == '\0' && little[0] == '\0')
		return (b);
	while (big[ib] != 0)
	{
		il = 0;
		if (little[il] == 0)
			return (b);
		while (little[il] == big[ib])
		{
			il++;
			ib++;
			if (little[il] == 0)
				return (b + ib - il);
			else if (big[ib] == 0)
				return (0);
		}
		ib = ib - il + 1;
	}
	return (0);
}
