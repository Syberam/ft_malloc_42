/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 13:12:03 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/10/23 19:48:41 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "../libft/libft.h"
# include <unistd.h>
# include <sys/mman.h>

# define TINY_ZONE					(size_t)(getpagesize() * 0)
# define SMALL_ZONE					(size_t)(getpagesize() * 0)
# define NB_BLOCKS					(size_t)128
# define TINY						(size_t)(TINY_ZONE/NB_BLOCKS)
# define SMALL						(size_t)(SMALL_ZONE/NB_BLOCKS)
# define KINDS						{TINY, SMALL}

# define ZHEAD_SIZE					sizeof(t_zonehead)

# define TINY_HEADER_CAPA			(int)(TINY/ZHEAD_SIZE)
# define SMALL_HEADER_CAPA			(int)(SMALL/ZHEAD_SIZE)

enum								e_alloc_size
{
	IS_TINY, IS_SMALL, IS_LARGE, IS_MASTER, NONE
};

typedef struct			s_zonehead
{
	enum e_alloc_size	kind;
	int					align;
	void				*fills;
	void				*frees;
	void				*next;
}						t_zonehead;

t_zonehead				*g_masterhead;

size_t					ft_align_size(size_t size);
enum e_alloc_size		ft_find_alloc_size(size_t size);

void					*malloc(size_t size);
void					*realloc(void *ptr, size_t size);
void					*ft_init_malloc(void);
void					*ft_extend_allocs(size_t size);
void					*ft_give_not_large(size_t size);
void					*ft_give_large(size_t size);

void					prepare_headers(void *link);
void					free(void *ptr);

/*	
t_zonehead				*ft_was_last_zone(t_zonehead *head, int kind);
t_zonehead				*ft_find_next_zone(t_zonehead *header, int kind);
t_zonehead				*ft_find_prev_zone(t_zonehead *header, int kind);

char					ft_check_master_head(void);
char					ft_which_size(size_t size);
char					*ft_print_hexa(void *addr);

void					*malloc(size_t size);

void					*ft_search_free_block(void *z_addr, char size);
void					*ft_search_notfull_zone(char kind);
void					*ft_newlarge(size_t size);
void					*ft_create_master_header(size_t size);
void					*ft_create_new_zone(char kind);
void					*ft_find_zone(void *zhead, void *ptr, int zone_kind);
void					ft_unfreed_blck(void);
void					show_alloc_mem(void);
void					ft_set_mheader_start(t_zonehead *start, int kind);

t_zonehead				*ft_set_master_header(void);
*/
#endif

/*

void *frees
void *filled
                   void *addr
|____HEAD____|  _/ void *next
|   *frees   |/
|   *filled  |\_
|            |   \ void *addr
|   *next    |     void *next_start
| kind       |






*/
