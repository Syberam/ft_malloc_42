/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 12:54:53 by sbonnefo          #+#    #+#             */
/*   Updated: 2017/01/31 19:09:18 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 5
# include <sys/types.h>
# include <sys/uio.h>
# include "libft/libft.h"

int			get_next_line(const int fd, char **line);

#endif
