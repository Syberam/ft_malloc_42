/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 17:41:09 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/22 18:04:30 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "includes/malloc.h"
int		main( void ){
	void	*addr;

	if (!(addr = malloc(0)))
		printf("MALLOC FAILED : %p\n", addr);
	else
		printf("addr : %p\n", addr);
	printf("________________________\n");
	if (!(addr = malloc(-1)))
		printf("MALLOC FAILED : %p\n", addr);
	else
		printf("addr : %p\n", addr);
	printf("________________________\n");
	if (!(addr = malloc(LONG_MIN)))
		printf("MALLOC FAILED : %p\n", addr);
	else
		printf("addr : %p\n", addr);
	printf("________________________\n");
	printf("size : %lu\n", sizeof(t_zonehead));
	printf(" -1 en ul : %lu", (size_t)(-1));
	printf(" var name : %s", @addr);
	return (0);
}

