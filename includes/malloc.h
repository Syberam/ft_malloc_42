/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbonnefo <sbonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 19:06:56 by sbonnefo          #+#    #+#             */
/*   Updated: 2018/12/14 16:37:28 by sbonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include "libft.h"
# include <unistd.h>
# include <sys/mman.h>
# include <pthread.h>

# define TINY_ZONE					(size_t)(getpagesize() * 16)
# define SMALL_ZONE					(size_t)(getpagesize() * 32)
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
	void				*start;
	void				*fills;
	void				*next;
	void				*end;
}						t_zonehead;

t_zonehead				*g_masterhead;
extern pthread_mutex_t	g_mutex;

size_t					ft_align_size(size_t size);
enum e_alloc_size		ft_find_alloc_size(size_t size);

void					*malloc(size_t size);
void					*ft_malloc(size_t size);
void					*calloc(size_t count, size_t size);
void					*realloc(void *ptr, size_t size);
void					*ft_init_malloc(void);
void					*ft_extend_zone_header(void);
void					*ft_give_not_large(size_t size);
void					*ft_give_large(size_t size);
void					*ft_give_new_header(void);

void					free(void *ptr);
void					ft_free(void *ptr);
void					show_alloc_mem(void);
size_t					show_larges_mem(void *master_head);

#endif

/*
** ******************************* GENERAL SCHEM********************************
**    MASTER  |  ZONE HEADER  |
**
**    |"""""|
**    |     |
**    |-----|
**                |"""""|-> META     |""||""||""||""||""||""||""||""""""""""|
**  TINY/SMALL {  |     |    |       |__||__||__||__||__||__||__||__________|
**                |-----|    |-> DATA[  ][  ][  ][  ][  ][  ][  ][          ]
**                |"""""|
**   EMPTY     {  |     |
**                |-----|
**                |"""""|
**   LARGE     {  |     |-> DATA     [                              ]
**                |-----|
**                |"""""|
**   EMPTY     {  |     |
**                |-----|
**                :     :
**                : ... :
**                :     :
**                |"""""|
**   EMPTY     {  |     |
**                |-----|
**
** *****************************************************************************
** **************************** WHITOUT frees***********************************
**
** HEADER MASTER
**    ===============
**   ||             ||
**   ||   start     ||-------------
**   ||   fills     ||--------     |
**   ||   next      ||-----   |    |
**   ||   end       ||--   |  |    |
**   ||             ||  |  |  |    |
**    ===============   |  |  |    |
**                      |  |  |    V             NULL
** Z                    |  |  |    ____________   ^
** O                    |  |  |   |            |  |   [  ][  ][            ]
** N                    |  |  |   |   next     |--    [  ][  ][            ]
** E                    |  |  |   |   start    |------^   ^                ^
** S                    |  |  |   |   fills    |----------|                |
**                      |  |  |   |   end      |---------------------------
** H                    |  |  |   |            |
** E                    |  |  |    ____________   ^                 TINY/SMALL
** A                    |  |  |    ____________   |
** D                    |  |  |   |            |  |
** E                    |  |  |   |   next     |--
** R                    |  |  |   |   start    |
** S                    |  |  |   |   fills    |
**                      |  |  |   |   end      |
**                      |  |  |   |            |
**                      |  |  |    ____________   ^
**                      |  |  |    ____________   |
**                      |  |  |-> |            |  |
**                      |  |      |   next     |--
**                      |  |      |   start    |---> [                        ]
**                      |  |      |   fills    |                             ^
**                      |  |      |   end      |-----------------------------|
**                      |  |      |            |
**                      |  |       ____________                          LARGE
**                      |  |       ____________
**                      |  |----> |            |
**                      |         |            |
**                      |         !            !
**                      |         :            :
**                      |         :            :
**                      |         :            :
**                      |         ¡            ¡
**                      |         |            |
**                      |-------> |____________|
**
**
**        # With free header, Next point to next free zone
**        # and HEADER_MASTER->next point to first free header
**
** *****************************************************************************
** ***************** WHITOUT frees : Zones Header LARGE Focus*******************
**
** ZONE HEADER           ^
**    ===============    |       ?    fills == NULL
**   ||             ||   |      //         ==>LARGE ( | a free header)
**   ||   next      ||---'
**   ||   start     ||-------------.
**   ||   fills     || ? == NULL x |
**   ||   end       ||--           |
**   ||             ||  |          |
**    ===============   |          |
**                      |          V
** L                    |          ____________
** A                    |         |            |
** R                    |         |            |
** G   size =           |         |            |
** E     end - start    |         |            |
**                      |         |            |
** C                    |         |            |
** A                    |------->  ____________
** S
** E
**
** *****************************************************************************
** ************ AFTER ZONE CREATION : Zones Header TINY/SMALL Focus*************
**                                TRANSITORY CASE
**
**
** ZONE HEADER           ^
**    ===============    |
**   ||             ||   |
**   ||   next      ||---
**   ||   start     ||-------------.     ? start == start->next ==> TINY/SMALL
**   ||   fills     || = NULL      |
**   ||   end       ||--           |     (better put fulls = end ???)
**   ||             ||  |          |
**    ===============   |          |
**                      |          V
**                      |         .____________.        --->.____________.
**                      |  [•]--> |            |       |    |            |
**                      |         |fills = NULL|       |    |            |
**                      |         !   start    !-------     !            !
**                      |         :   end      :-------     :            :
**                      |         : next = [•] :       |    :            :
**                      |         :            :       |    :            :
**                      |         ¡            ¡       |    ¡            ¡
**                      |         |            |       |    |            |
**                      |-------> |____________|        --->|____________|
**
** *****************************************************************************
** *********** AFTER FULL ZONE FREE : Zones Header TINY/SMALL Focus*************
**
**
**
** ZONE HEADER           ^
**    ===============    |
**   ||             ||   |
**   ||   next      ||---
**   ||   start     ||-------------.     ? start == start->next ==> TINY/SMALL
**   ||   fills     || = NULL      |
**   ||   end       ||--           |
**   ||             ||  |          |
**    ===============   |          |
**                      |          V
**                      |         .____________.        --->.____________.
**                      |  [•]--> |            |       |    |            |
**                      |         |fills = NULL|       |    |            |
**                      |         !   start    !-------     !            !
**                      |         : end  = NULL:            :            :
**                      |         : next = NULL:            :            :
**                      |         :            :            :            :
**                      |         ¡            ¡            ¡            ¡
**                      |         |            |            |            |
**                      |         |____________|       .--->|____________|
**                      |______________________________|
**
** *****************************************************************************
** *************** WITHOUT frees : Zones Header TINY/SMALL Focus****************
**
**      ZONE HEADER            |    BLOCKS HEADS    |      DATA BLOCKS
**  ~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~
**   ||             ||         |                    |
**    ===============          |                    |
**                       ^     |                    |
**    ===============    |     :                    |
**   ||             ||   |     .                    |
**   ||   next      ||---'                          :
**   ||   start     ||-------------.                .
**   ||   fills     ||--------.    |
**   ||   end       ||--.     |    |
**   ||             ||  |     |    |
**    ===============   |     |    |
**                      |     |    V              ^
** Z                    |     |    ____________   |   .---> .____________.
** O                    |     |   |            |  |   |     |            |
** N                    |     |   |   fills    |--'   |     | USER  DATA |
** E   size =           |     |   |   start    |------'     |            |
** S     end->end       |     |   |   end      |----------> |------------|
**     - start->start   |     |   |   next     |-----.      |    FREE    |
** H                    |     |   |            |     |      |    SPACE   |
** E                    |     |    ____________   ^  V       ____________
** A                    |     |    ____________   |    --->  ____________
** D                    |     |   |            |  |   |     |            |
** E                    |     |   |   fills    |--    |     |    DATA    |
** R                    |     |   |   start    |------      |            |
** S                    |     |   |   end      |----------> |------------|
**                      |     |   |   next     |-----.      |            |
**                      |     |   |            |     |      |            |
**                      |     |    ____________   ^  V       ____________
**                      |     |    ____________   |    --->  ____________
**                      |     |-> |            |  |   |     |            |
**                      |         |   fills    |--    |     |    DATA    |
**                      |         |   start    |------      |            |
**                      |         |   end      |----------> |------------|
**                      |         |   next     |----.       |            |
**                      |         |            |    |       |            |
**                      |          ____________     V        ____________
**        zone_size --->|                          [•]
**                      |
**                      |
**                      |
**                      |
**                      |  [•]---> ____________         ---> ____________
**                      |         |            |       |    |            |
**                      |         |fills = NULL|       |    |            |
**                      |         !   start    !-------     !            !
**                      |         : end  = NULL:            :            :
**                      |         : next = NULL:            :            :
**                      |         :            :            :            :
**                      |         ¡            ¡            ¡            ¡
**                      |  \ /    |            |            |            |
**                      |---X---> |____________|        .-->|____________|
**                      |  / \ |-> = Zone_head->start   |
**                      |  + NB_BLOCKS * sizeof(head)   |
**                      |                               |
**                      |-------------------------------'
**
**    if FULL zone_header->fills->next = NULL;
**
** *****************************************************************************
** **************** WITH frees : Zones Header TINY/SMALL Focus******************
**
**      ZONE HEADER            |    BLOCKS HEADS    |      DATA BLOCKS
**  ~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~.~
**   ||             ||         |                    |
**    ===============          |                    |
**                       ^     |                    |
**    ===============    |     :                    |
**   ||             ||   |     .                    |
**   ||   next      ||---'                          :
**   ||   start     ||-------------.                .
**   ||   fills     ||--------.    |
**   ||   end       ||--.     |    |
**   ||             ||  |     |    |
**    ===============   |     |    |
**                      |     |    V              ^
** Z                    |     |    ____________   |   .---> .____________.
** O                    |     |   |            |  |   |     |            |
** N                    |     |   |   fills    |--'   |     | USER  DATA |
** E   size =           |     |   |   start    |------'     |            |
** S     end->end       |     |   |   end      |----------> |------------|
**     - start->start   |     |   |   next     |-----.      |    FREE    |
** H                    |     |   |            |     |      |    SPACE   |
** E                    |     |    ____________   ^  V       ____________
** A                    |     |    ____________   |    --->  ____________
** D                    |     |   |            |  |   |     |            |
** E                    |     |   |   fills    |--    |     |    DATA    |
** R                    |     |   |   start    |------      |            |
** S                    |     |   |   end      |----------> |------------|
**                      |     |   |   next     |-----.      |            |
**                      |     |   |            |     |      |            |
**                      |     |    ____________   ^  V       ____________
**                      |     |    ____________   |    --->  ____________
**                      |     |-> |            |  |   |     |            |
**                      |         |   fills    |--    |     |    DATA    |
**                      |         |   start    |------      |            |
**                      |         |   end      |----------> |------------|
**                      |         |   next     |----.       |            |
**                      |         |            |    |       |            |
**                      |          ____________     V        ____________
**                      |                          [•]
**                      |
**                      |
**                      |                        ???
**                      |                         ^
**                      |  [•]---> ____________   |    --->  ____________
**                      |         |            |  |   |     |            |
**                      |         |   fills    |--    |     |    FREE    |
**                      |         |   start    |------|     |    LINK    |
**                      |         |   end      |------'     |            |
**                      |         |   next     |----.       |            |
**                      |         |            |    |       |            |
**                      |          ____________     V        ____________
**                      |          ____________         ---> ____________
**                      |         |            |       |    |            |
**                      |         |fills = NULL|       |    |            |
**                      |         !   start    !-------     !            !
**                      |         : end  = NULL:            :            :
**                      |         : next = NULL:            :            :
**                      |         :sizeof(head):            :            :
**                      |         ¡            ¡            ¡            ¡
**                      |  \ /    |            |            |            |
**                      |---X---> |____________|        .-->|____________|
**                      |  / \ |-> = Zone_head->start   |
**                      |  + NB_BLOCKS * sizeof(head)   |
**                      |                               |
**                      |-------------------------------'
**
**    if FULL zone_header->fills->next = NULL;
**
** *****************************************************************************
*/
